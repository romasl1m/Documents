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

vector<int> wec[50'001];

int dfs(int w = 1, int p = 0) {
    // cout << "W " << w << endl;
    int cur = 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        cur = (cur * (dfs(ss))) % mod;
    }

    for (int ss : wec[w]) {
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
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
