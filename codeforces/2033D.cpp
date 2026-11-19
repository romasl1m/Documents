/*
Now playing:
Quavo - Away (feat. Offset) [QRÖMELIFE]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <map>
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

int f() {
    int n;
    cin >> n;
    vector<int> tab(n + 1), pref(n + 1), last(n + 1, -1), dp(n + 1);
    map<int, int> mapa;
    mapa[0] = 0;

    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
        pref[i] = pref[i - 1] + tab[i];

        if (mapa.find(pref[i]) == mapa.end())
            last[i] = -1;
        else
            last[i] = mapa[pref[i]];
        mapa[pref[i]] = i;
    }

    droptop(i, 1, n + 1)
    {
        // dp[i] = max({dp[i], dp[i - 1], (last[i] == -1 ? -2e9 : dp[last[i]])});
        dp[i] = max(dp[i], dp[i - 1]);
        if (last[i] != -1)
            dp[i] = max(dp[i], dp[last[i]] + 1);
    }

    int res = 0;
    droptop(i, 1, n + 1)
    {
        res = max(res, dp[i]);
    }
    return res;

    return 0;
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
