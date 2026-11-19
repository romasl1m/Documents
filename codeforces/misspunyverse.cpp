/*
Now playing:
Lil Peep - haunt u [LIVE FOREVER]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll tab[3'001];
vector<int> wec[3'001];
int siz[3'001];
int n, m;
pair<ll, ll> dp[3'001][3'001];

void f(int w, int ss) {
    droptop(0, siz[w])
    {
        dp[0][i] = dp[w][i];
    }
    droptop(0, siz[ss] + siz[w])
    {
        dp[w][i] = {-1e18, 0};
    }
    droptop(0, siz[w])
    {
        for (int j = 0; j <= siz[ss]; j++) {
            dp[w][i + j] = max(dp[w][i + j], {dp[0][i].first + dp[ss][j].first, dp[0][i].second + dp[ss][j].second});
        }
    }
}

void dfs(int w, int p = -1) {
    siz[w] = 1;
    dp[w][0] = {0, tab[w]};
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        f(w, ss);
        siz[w] += siz[ss];
    }
    dp[w][siz[w]] = {-1e18, 0};
    for (int i = siz[w]; i > 0; i--) {
        dp[w][i] = max(dp[w][i], {dp[w][i - 1].first + (dp[w][i - 1].second > 0), 0});
    }
}
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        cin >> n >> m;
        droptop(1, n + 1)
        {
            wec[i].clear();
            cin >> tab[i];
        }
        droptop(1, n + 1)
        {
            ll x;
            cin >> x;
            tab[i] = x - tab[i];
        }
        droptop(1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }
        dfs(1);
        cout << dp[1][m - 1].first + (dp[1][m - 1].second > 0) << "\n";
    }
    return 0;
}
