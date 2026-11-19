/*
Now playing:
Fukaj - NIE CHCĘ WRACAĆ [INTERLUDIUM]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

bool wiz[200'001];
void dfs(int w, const vector<vector<pair<int, ll>>> &wec, int &lstw) {
    wiz[w] = true;
    for (const auto &[ss, cost] : wec[w]) {
        if (not wiz[ss])
            dfs(ss, wec, lstw);
    }
    lstw = w;
}
#define dfs dontuse
int checkf(int w, const vector<vector<pair<int, ll>>> &wec) {
    int res = 1;
    wiz[w] = true;
    for (const auto &[ss, cost] : wec[w]) {
        if (not wiz[ss])
            res += checkf(ss, wec);
    }
    return res;
}
#undef dfs

int f() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> wec(n + 1);
    droptop(i, 0, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        wec[a].pb({b, c});
    }

    int l = -1, r = 1e9 + 1;
    while (l < r - 1) {
        int mid = l + ((r - l) >> 1);
        vector<vector<pair<int, ll>>> cur(n + 1);

        droptop(w, 1, n + 1)
        {
            for (const auto &[b, c] : wec[w]) {
                cur[w].pb({b, c});
                if (c <= mid)
                    cur[b].pb({w, c});
            }
        }
#define wec dontuse

        droptop(i, 1, n + 1)
        {
            wiz[i] = false;
        }
        int lstw = 1;

        droptop(i, 1, n + 1)
        {
            if (not wiz[i])
                dfs(i, cur, lstw);
        }
        droptop(i, 1, n + 1)
        {
            wiz[i] = false;
        }

        if (checkf(lstw, cur) == n)
            r = mid;
        else
            l = mid;
    }
#define res r
    return res == 1e9 + 1 ? -1 : res;
#undef res
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
