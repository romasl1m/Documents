/*
Now playing:

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll
const int mod = 1'000'696'969;

int dp[50'001][2];
vector<int> wec[50'001];

void dfs(int w = 1, int p = 0) {
    // cout << "W " << w << endl;
    dp[w][0] = 1, dp[w][1] = 0;

    vector<int> wec2;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        wec2.pb(ss);
    }

    droptop(i, 0, wec2.size())
    {
        int ss = wec2[i];
        dp[w][0] = (dp[w][0] * (dp[ss][1] + dp[ss][0]) % mod) % mod;
    }

    vector<int> pref(wec[w].size() + 1, 1);
    vector<int> suf(wec[w].size() + 1, 1);
    droptop(i, 0, wec2.size())
    {
        int ss = wec2[i];
        pref[i + 1] = (pref[i] * (dp[ss][0] + dp[ss][1])) % mod;
    }

    for (int i = wec2.size() - 1; i >= 0; i--) {
        int ss = wec2[i];
        suf[i] = (suf[i + 1] * (dp[ss][0] + dp[ss][1])) % mod;
    }
    // droptop(i, 0, wec[w].size())
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // droptop(i, 0, wec[w].size())
    // {
    //     cout << suf[i] << " ";
    // }

    // cout << "w = " << w << endl;
    // droptop(i, 0, wec[w].size())
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // droptop(i, 0, wec[w].size())
    // {
    //     cout << suf[i] << " ";
    // }
    // cout << endl
    //      << endl;
    droptop(i, 0, wec2.size())
    {
        int ss = wec2[i];
        int cur = (pref[i] * suf[i + 1]) % mod;
        dp[w][1] = (dp[w][1] + (cur * dp[ss][0]) % mod) % mod;
        // if (wec[w][i] == p)
        //     continue;
        // dp[w][1] = (dp[w][1] + (pref[i] + suf[i + 1]) * dp[wec[w][i]][0]) % mod;
        // cout << pref[i] << " " << suf[i] << " " << dp[wec[w][i]][0] << endl;
        // dp[w][1] = (dp[w][1] + dz * dp[ss][0]) % mod;
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }
        dfs();

        // droptop(i, 1, n + 1)
        // {
        //     cout << wec[i].size() << " " << dp[i][0] << " " << dp[i][1] << endl;
        // }
        cout << (dp[1][0] + dp[1][1]) % mod;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
