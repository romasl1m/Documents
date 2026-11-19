/*
Now playing:
Lil Peep - Avoid [Avoid]
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
#define int ll

void dfs(int w, int p, vector<pair<int, int>> &dp, const vector<vector<int>> &wec, const vector<pair<int, int>> &tab) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, dp, wec, tab);
    }
    // dp[w] = tab[w];
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dp[w].first += max(dp[ss].first + abs(tab[w].first - tab[ss].first), dp[ss].second + abs(tab[w].first - tab[ss].second)),
            dp[w].second += max(dp[ss].second + abs(tab[w].second - tab[ss].second), dp[ss].first + abs(tab[w].second - tab[ss].first));
    }
}

int f() {
    int n;
    cin >> n;
    vector<pair<int, int>> tab(n + 1), dp(n + 1);
    vector<vector<int>> wec(n + 1);

    droptop(i, 1, n + 1)
    {
        cin >> tab[i].first >> tab[i].second;
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0, dp, wec, tab);
    // cerr << dp[1].first << " " << dp[1].second << "\n"
    //      << dp[2].first << " " << dp[2].second << endl;
    return max(dp[1].first, dp[1].second);
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
