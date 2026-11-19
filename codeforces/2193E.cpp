/*
Now playing:
Linkin Park - Stained [From Zero]
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
#define cookie(c, n, a) for (int c = (n); c >(a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

void f() {
    int n;
    cin >> n;
    vector<int> tab(n), dp(n + 1, 1e9);

    droptop(i, 0, n)
    {
        cin >> tab[i];
        dp[tab[i]] = true;
    }

    droptop(i, 1, n + 1)
    {
        for (int j = i; j <= n; j += i)
            dp[j] = min(dp[j], dp[i] + dp[j / i]);
        // dp[j] = dp[j] or (dp[i] and dp[j / i]);
    }

    droptop(i, 1, n + 1)
    {
        cout << (dp[i] == 1e9 ? -1 : dp[i]) << " ";
    }
    cout << "\n";
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}
