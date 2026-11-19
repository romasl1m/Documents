/*
Now playing:
Young Thug - With Them [Slime Season 3]
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
const int mod = 1e9 + 7;

void dfs(int w, const vector<int> &l, const vector<int> &r, vector<int> &dp) {
    if (l[w] == 0) {
        dp[w] = 1;
        return;
    }
    dfs(l[w], l, r, dp), dfs(r[w], l, r, dp);
    dp[w] = (dp[l[w]] + dp[r[w]] + 3) % mod;
}
void sum(int w, const vector<int> &l, const vector<int> &r, vector<int> &dp) {
    // cerr << "vertex " << w << " " << l[w] << " " << r[w] << endl;
    if (l[w] == 0)
        return;
    // cerr << dp[l[w]] << " " << dp[r[w]] << " " << dp[w] << endl;
    // cerr << "next vertices: " << l[w] << " " << r[w] << endl;
    dp[l[w]] = (dp[l[w]] + dp[w]) % mod,
    dp[r[w]] = (dp[r[w]] + dp[w]) % mod,
    sum(l[w], l, r, dp),
    sum(r[w], l, r, dp);
}

void f() {
    int n;
    cin >> n;
    vector<int> dp(n + 1), l(n + 1), r(n + 1);

    droptop(i, 1, n + 1)
    {
        cin >> l[i] >> r[i];
    }

    dfs(1, l, r, dp),
        sum(1, l, r, dp);

    droptop(i, 1, n + 1)
    {
        cout << dp[i] << " ";
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
