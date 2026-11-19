/*
Now playing:
Linkin Park - Blackout [A Thousand Suns]
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

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &sub, vector<int> &dp) {
    sub[w] = (wec[w].size() == 1);
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, wec, sub, dp);
        sub[w] += sub[ss];
    }

    int maksnp = 0;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        maksnp = max(maksnp, dp[ss] + (sub[ss] & 1 ? 1 : -1));
    }
    dp[w] = maksnp;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> sub(n + 1);
    vector<int> dp(n + 1);

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0, wec, sub, dp);

    int res = 0;
    droptop(i, 2, n + 1)
    {
        if (sub[i] & 1)
            res++;
    }

    // cerr << "\ndeb\n";
    // for (int i = 1; i <= n; i++)
    //     cerr << dp[i] << " ";
    // cerr << endl;
    // << endl;

    if (not(sub[1] & 1))
        cout << res << "\n";
    else
        cout << res - dp[1] << "\n";
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
