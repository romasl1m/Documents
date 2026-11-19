/*
Now playing:
Pop Smoke - Christopher Walking [Meet The Woo 2 (Deluxe)]
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

int tab[200'001];
int f() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    droptop(i, 0, n)
    {
        cin >> tab[i];
        // cerr << i << " " << tab[i] << " ";
    }

    if (n == 1)
        return tab[0];

    droptop(i, 0, n)
    {
        if (i + 1 <= n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + tab[i]);

            if (i + 2 <= n)
                dp[i + 2] = min(dp[i + 2], dp[i] + tab[i]);
            if (i + 3 <= n)
                dp[i + 3] = min(dp[i + 3], dp[i] + tab[i]);
        }

        if (i + 2 <= n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + tab[i] + tab[i + 1]);

            if (i + 3 <= n)
                dp[i + 3] = min(dp[i + 3], dp[i] + tab[i] + tab[i + 1]);
            if (i + 4 <= n)
                dp[i + 4] = min(dp[i + 4], dp[i] + tab[i] + tab[i + 1]);
        }
    }

    // cerr << endl
    //      << "dp ";
    // droptop(i, 0, n + 1)
    // {
    //     cerr << dp[i] << " ";
    // }
    // cerr << endl;

    return dp[n];
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        // f();
        cout << f();
        cout << "\n";
    }
    return 0;
}
