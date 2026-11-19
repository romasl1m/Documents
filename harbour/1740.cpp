/*
Now playing:
Bring Me The Horizon - Kingslayer (feat. BABYMETAL) [POST HUMAN: SURVIVAL HORROR]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long
#define int ll

const int START = 0, QUERY = 1, END = 2;
int tab[100'001][4];
struct event {
    int x, y, type;

    bool operator<(const event &other) const {
        if (x != other.x)
            return x < other.x;
        return type < other.type;
    }
};

vector<int> ys;
int gety(int y) {
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
}

const int base = 1'000'001;
int tree[base];
void add(int pos, int war) {
    for (int j = pos; j <= (int)ys.size(); j += j & -j)
        tree[j] += war;
}
int query(int x) {
    int res = 0;
    for (int j = x; j > 0; j -= j & -j)
        res += tree[j];
    return res;
}

void f() {
    int n;
    cin >> n;
    vector<event> wec;

    droptop(i, 0, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        tab[i][0] = x1, tab[i][1] = y1, tab[i][2] = x2, tab[i][3] = y2;

        if (y1 == y2)
            wec.pb({x1, y1, START}),
                wec.pb({x2, y2, END}),
                ys.pb(y1);
        else
            wec.pb({x1, i, QUERY}),
                ys.pb(y1), ys.pb(y2);
    }
    hotbox(ys);
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    hotbox(wec);

    int res = 0;
    for (const event &evt : wec) {
        if (evt.type == START)
            add(gety(evt.y), 1);
        else if (evt.type == END)
            add(gety(evt.y), -1);
        else
            res += query(gety(tab[evt.y][3])) - query(gety(tab[evt.y][1]) - 1);
        // res += query(tab[evt.y][3]) - query(tab[evt.y][1]);
        // res += distance(cur.lower_bound(tab[evt.y][1]), cur.upper_bound(tab[evt.y][3]));
    }

    cout << res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
