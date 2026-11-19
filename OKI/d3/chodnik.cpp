/*
Now playing:
HXG - FACET!ME [Homixide Lifestyle 2]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); ++c)
#define pb push_back
#define ll long long

struct evt {
    int x, y, id;
};
bool comp(const evt &a, const evt &b) {
    if (a.x == b.x) {
        return a.id < b.id;
    }
    return a.x < b.x;
}

#define hotbox(wec) sort(wec.begin(), wec.end(), comp);

const int base = (1 << 21);
int tree[base + 1];
void add(int i, int war) {
    i++;
    while (i <= base) {
        tree[i] += war, i += i & -i;
    }
}
int query(int i) {
    i++;
    int res = 0;
    while (i > 0) {
        res += tree[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        if (!(cin >> n))
            break;

        vector<evt> events;
        vector<int> ys;

        int p = 100000;
        events.reserve(n + 8 * p);
        ys.reserve(n + 8 * p);

        droptop(i, 0, n)
        {
            int x, y;
            cin >> x >> y;
            events.pb({x, y, -1});
            ys.pb(y);
        }

        cin >> p;
        droptop(cur, 0, p)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int pos = (cur << 1) | 1;
            int neg = (cur << 1) | 0;

            events.pb({x2, y2, pos});
            events.pb({x1 - 1, y2, neg});
            events.pb({x2, y1 - 1, neg});
            events.pb({x1 - 1, y1 - 1, pos});

            ys.pb(y1 - 1);
            ys.pb(y2);

            if (x1 + 1 <= x2 - 1 and y1 + 1 <= y2 - 1) {
                int x11 = x1 + 1, x22 = x2 - 1, y11 = y1 + 1, y22 = y2 - 1;
                events.pb({x22, y22, neg});
                events.pb({x11 - 1, y22, pos});
                events.pb({x22, y11 - 1, pos});
                events.pb({x11 - 1, y11 - 1, neg});

                ys.pb(y11 - 1);
                ys.pb(y22);
            }
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        for (auto &evt : events) {
            evt.y = lower_bound(ys.begin(), ys.end(), evt.y) - ys.begin() + 1;
        }

        vector<int>().swap(ys);
        hotbox(events);

        vector<int> res(p, 0);
        for (const auto &evt : events) {
            if (evt.id == -1) {
                add(evt.y, 1);
            } else {
                int id = evt.id >> 1;
                int war = (evt.id & 1) ? 1 : -1;
                res[id] += war * query(evt.y);
            }
        }
        droptop(i, 0, p)
        {
            cout << res[i] << "\n";
        }
    }
    return 0;
}
