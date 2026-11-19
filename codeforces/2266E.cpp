/*
Now playing:
Linkin Park - Unshatter [From Zero (Deluxe Edition)]
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

void f() {
    int n, k;
    cin >> n >> k;

    vector<ll> tab(n);
    ll res = 0, maks = 0;
    droptop(i, 0, n)
    {
        cin >> tab[i];
        maks = max(maks, tab[i]);
    }
    if (maks <= k) {
        cout << 0;
        return;
    }
    vector<ll> dp(n + 1, 0);

    droptop(i, k + 1, maks + 1)
    {
        dp[i] = 1e18;
        ll cur = i;

        for (int j = 2; j * j <= cur; j++) {
            if (cur % j == 0) {
                dp[i] = min(dp[i], j * dp[i / j] + 1);
                while (cur % j == 0)
                    cur /= j;
            }
        }

        if (cur > 1)
            dp[i] = min(dp[i], dp[i / cur] * cur + 1);
    }

    droptop(i, 0, n)
    {
        res += dp[tab[i]];
    }
    cout << res;
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
