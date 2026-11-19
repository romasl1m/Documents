/*
Now playing:
Linkin Park - BURN IT DOWN [LIVING THINGS]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

void dfs(int w, int p, const vector<vector<int>> &wec, const vector<ll> &tab, vector<vector<ll>> &dp) {
    vector<ll> suf(24);
    droptop(i, 1, 23)
    {
        dp[w][i] = (ll)i * tab[w];
    }

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, wec, tab, dp);

        suf[23] = 1e18;
        cookie(i, 22, 1)
        {
            suf[i] = min(suf[i + 1], dp[ss][i]);
        }
        ll cur = 2e18;
        droptop(i, 1, 23)
        {
            dp[w][i] += min(suf[i + 1], cur),
                cur = min(cur, dp[ss][i]);
        }
    }
}

ll f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(24));
    vector<ll> tab(n + 1);
    ll sum = 0;

    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
        sum += tab[i];
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0, wec, tab, dp);

    ll res = 2e18;
    droptop(i, 1, 23)
    {
        res = min(res, dp[1][i]);
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << f();
        cout << "\n";
    }
    return 0;
}
