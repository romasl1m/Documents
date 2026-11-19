/*
Now playing:
Offset - Pink Tops [GMFU]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long
#define int ll

int tab[100'001];
vector<int> wec[100'001];
map<int, int> mapa[100'001];
pair<int, ll> res[100'001];

void dfs(int w, int p) {
    int heavy = 0;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        if (mapa[ss].size() > mapa[heavy].size())
            heavy = ss;
    }
    if (not heavy) {
        mapa[w][tab[w]]++;
        res[w] = {1, tab[w]};
    } else {
        mapa[w] = move(mapa[heavy]);
        res[w] = res[heavy];

        ll nw = ++mapa[w][tab[w]];
        if (nw == res[w].first)
            res[w].second += tab[w];
        else if (nw > res[w].first)
            res[w].first = nw, res[w].second = tab[w];

        for (int ss : wec[w]) {
            if (ss == p or ss == heavy)
                continue;
            for (const auto &[a, b] : mapa[ss]) {
                mapa[w][a] += b;
                nw = mapa[w][a];

                if (nw == res[w].first)
                    res[w].second += a;
                else if (res[w].first < nw)
                    res[w].first = nw, res[w].second = a;
            }
        }
    }
}

int f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }
    dfs(1, 0);
    droptop(i, 1, n + 1)
    {
        cout << res[i].second << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
