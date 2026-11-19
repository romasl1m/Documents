/*
Now playing:
HXG - Versus [Versus]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

bool agent[500'001];
vector<int> wec[500'001];
int dp[500'001][3];
void dfs(int w, int p) {
    int sum = 0, maksup = -1e9, maksdown = -1e9;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        sum += dp[ss][2];
    }

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        maksup = max(maksup, sum - dp[ss][2] + dp[ss][0] + 1),
        maksdown = max(maksdown, sum - dp[ss][2] + dp[ss][1] + 1);
    }

    if (agent[w]) {
        dp[w][0] = sum,
        dp[w][1] = -1e9,
        dp[w][2] = max(sum, maksdown);
    } else {
        dp[w][0] = maksup,
        dp[w][1] = max(sum, maksdown);

        int both = -1e9, none = 0, up = -1e9, down = -1e9;
        for (int ss : wec[w]) {
            if (ss == p)
                continue;
            both = max({both + dp[ss][2], down + dp[ss][0] + 1, up + dp[ss][1] + 1}),
            up = max(up + dp[ss][2], none + dp[ss][0] + 1),
            down = max(down + dp[ss][2], none + dp[ss][1] + 1),
            none += dp[ss][2];
        }
        dp[w][2] = max({sum,
                        maksup,
                        both});
    }
}

void f() {
    int n, k;
    cin >> n >> k;
    droptop(i, 0, k)
    {
        int x;
        cin >> x;
        agent[x] = true;
    }

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0);
    cout << ((n - k) << 1) - dp[1][2];
}

int main() {
    raindrop;
    int t = 1;
    while (t--)
        f();
    return 0;
}
