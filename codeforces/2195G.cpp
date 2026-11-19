/*
Now playing:
Linkin Park - War [The Hunting Party]
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

void dfs(int w, const vector<int> &l, const vector<int> &r, vector<ll> &dp) {
    if (l[w] == 0) {
        dp[w] = 1;
        return;
    }
    dfs(l[w], l, r, dp), dfs(r[w], l, r, dp);
    dp[w] = (dp[l[w]] + dp[r[w]] + 3);
}
void sum(int w, const vector<int> &l, const vector<int> &r, vector<ll> &dp, vector<vector<int>> &lca, vector<int> &ord, vector<int> &in) {
    in[w] = ord.size();
    // droptop(i, 1, 20)
    // {
    //     lca[w][i] = lca[lca[w][i - 1]][i - 1];
    // }

    if (l[w] == 0) {
        ord.pb(w);
        return;
    }
    dp[l[w]] = (dp[l[w]] + dp[w]),
    dp[r[w]] = (dp[r[w]] + dp[w]),
    ord.pb(w),
    sum(l[w], l, r, dp, lca, ord, in),
    ord.pb(w),
    sum(r[w], l, r, dp, lca, ord, in),
    ord.pb(w);
}

void f() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> lca(n + 1, vector<int>(20));
    vector<ll> dp(n + 1);
    vector<int> l(n + 1), r(n + 1), ord, in(n + 1);
    lca[1][0] = true;
    ord.reserve(n * 3);

    droptop(i, 1, n + 1)
    {
        cin >> l[i] >> r[i];
        if (l[i] == 0)
            continue;
        lca[l[i]][0] = lca[r[i]][0] = i;
    }

    dfs(1, l, r, dp),
        sum(1, l, r, dp, lca, ord, in);
    droptop(i, 1, 20)
    {
        droptop(j, 1, n + 1)
        {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    while (q--) {
        ll start, k;
        cin >> start >> k;
        ll w = start;
        cookie(i, 19, 0)
        {
            if (lca[w][i] == 0)
                continue;
            if (dp[start] <= k + dp[lca[w][i]])
                w = lca[w][i];
            // if (dp[lca[w][i]] + k >= dp[w])
            //     w = lca[w][i];
        }
        cout << ord[in[w] + k + dp[w] - dp[start]] << " ";
    }
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
