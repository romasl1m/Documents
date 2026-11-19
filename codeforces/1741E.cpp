/*
Now playing:
Artemas - dirty little secret [dirty little secret]
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

bool dp[200'001];
int f() {
    int n;
    cin >> n;
    vector<int> tab(n + 1);
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
        dp[i] = false;
    }
    dp[0] = true;

    droptop(i, 1, n + 1)
    {
        if (i - tab[i] - 1 >= 0 and dp[i - tab[i] - 1])
            dp[i] = true;
        // cerr << i << " " << dp[i] << " ";
        if (i + tab[i] <= n and dp[i - 1])
            dp[i + tab[i]] = true;
        // cerr << i << " " << dp[i + tab[i]] << endl;
    }

    // droptop(i, 0, n)
    // {
    //     cout << dp[i] << " ";
    // }
    // cerr << endl;
    return dp[n];
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << (f() ? "yes\n" : "no\n");
    }
    return 0;
}
