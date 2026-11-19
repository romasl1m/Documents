/*
Now playing:
Linkin Park - Don't Stay [Meteora (Bonus Edition)]
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
#define int ll

int dp[100'001];
const int mod = 1e9 + 7;

int f(const int &k) {
    dp[0] = 1;
    droptop(i, 1, 100'001)
    {
        if (i < k) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = (dp[i - 1] + dp[i - k]) % mod;
        }
    }

    // droptop(i, 1, 5)
    // {
    //     cout << dp[i] << " ";
    // }

    droptop(i, 1, 100'001)
    {
        dp[i] = (dp[i] + dp[i - 1]) % mod;
    }

    return 0;
}

signed main() {
    raindrop;
    int t = 1, k;
    cin >> t >> k;
    f(k);
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (mod + dp[b] - dp[a - 1]) % mod;
        cout << "\n";
    }
    return 0;
}
