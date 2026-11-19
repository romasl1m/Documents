/*
Now playing:
Linkin Park - High Voltage [Hybrid Theory (Bonus Edition)]
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

ll dp[361][361], makst[361];

int f() {
    int n, k;
    cin >> n >> k;
    vector<int> tab, pref;
    int maks = 0;
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        if (x > maks) {
            maks = x, tab.pb(x), pref.pb(i);
        }
    }
    pref.pb(n);
    droptop(i, 0, k + 1)
    {
        droptop(j, 0, k + 1)
        {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = false;

    droptop(i, 0, tab.size())
    {
        int cur = tab[i], len = pref[i + 1] - pref[i];
        droptop(sum, 0, k + 1)
        {
            ll best = -1e9;
            droptop(t, 0, sum + 1)
            {
                best = max(best, dp[sum][t]);
            }
            makst[sum] = best;
        }
        droptop(sum, 0, k + 1)
        {
            droptop(maks, 0, sum + 1)
            {
                if (maks >= 1 and maks <= cur)
                    dp[sum][maks] = max(dp[sum][maks], makst[sum - maks]);
                dp[sum][maks] = (dp[sum][maks] >= 0 ? dp[sum][maks] + maks * len : -1e9);
            }
        }
    }

    ll res = 0;
    droptop(i, 0, k + 1)
    {
        droptop(j, 0, k + 1)
        {
            res = max(res, dp[i][j]);
        }
    }
    return res;
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
