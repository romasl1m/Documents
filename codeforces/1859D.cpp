/*
Now playing:
Bring Me The Horizon - Kingslayer (feat. BABYMETAL) [POST HUMAN: SURVIVAL HORROR]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
// #include <multiset>
#include <set>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

const int ending = 1, start = -1, query = 0;
struct st {
    int pos, type, id;
    bool operator<(const st &other) const {
        if (pos == other.pos)
            return type < other.type;
        return pos < other.pos;
    }
};

int f() {
    int n;
    cin >> n;
    vector<st> wec;
    wec.reserve(n << 1);
    vector<int> res(n + 1);
    droptop(i, 0, n)
    {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        wec.pb({l, start, i}),
            wec.pb({b, ending, i}),
            res[i] = b;
    }
    int q;
    cin >> q;
    vector<int> tab(q);
    wec.reserve((n << 1) + q);
    droptop(i, 0, q)
    {
        int x;
        cin >> x;
        tab[i] = x, wec.pb({x, query, i});
    }

    multiset<int> cur;
    sort(hotbox(wec)),
        reverse(hotbox(wec));
    for (const auto &[pos, type, id] : wec) {
        if (type == ending) {
            if (not cur.empty())
                res[id] = *cur.rbegin();
            cur.insert(res[id]);
        } else if (type == query) {
            if (not cur.empty())
                tab[id] = max(tab[id], *cur.rbegin());
        } else {
            cur.erase(cur.find(res[id]));
        }
    }
    droptop(i, 0, q)
    {
        cout << tab[i] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
