/*
Now playing:
Playboi Carti - On That Time [Whole Lotta Red]
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

int in[200'001], out[200'001], dp[200'001];
vector<int> wec[200'001];

int dfs(int w) {
    if (dp[w] > 0)
        return dp[w];
    if (in[w] >= 2) {
        if (out[w] >= 2) {
            dp[w] = 1;
            for (int ss : wec[w]) {
                dp[w] = max(dp[w], dfs(ss) + 1);
            }
        } else {
            dp[w] = 1;
        }
    } else
        dp[w] = -1e9;
    return dp[w];
}

int f() {
    int n, m;
    cin >> n >> m;

    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), in[b]++, out[a]++;
    }

    int res = 1;
    droptop(w, 1, n + 1)
    {
        if (out[w] >= 2) {
            for (int ss : wec[w]) {
                res = max(res, dfs(ss) + 1);
            }
        }
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
