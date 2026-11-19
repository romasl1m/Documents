/*
Now playing:
J. Cole - Bombs in the Ville/Hit the Gas [The Fall-Off]
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
#include <queue>

int n, m, d, k;
bool comp(const vector<int> &a, const vector<int> &b) {
    if (a.empty())
        return true;
    bool better = false;
    droptop(i, 0, k)
    {
        if (b[i] > a[i])
            better = true;
        if (b[i] < a[i])
            return false;
    }
    return better;
}
vector<int> dp[10'001];
int tab[10'001][10];
vector<pair<int, int>> wec[10'001];

void fk1() {
    vector<int> dist(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({1, 0});
}

void dfs(int w, int cur, vector<int> sw) {
    if (cur >= d)
        return;
    if (w == 3)
        cerr << "wiz " << w << " " << cur << " " << sw[0] << " " << sw[1] << endl;

    for (auto [ss, id] : wec[w]) {
        vector<int> nxtsw = sw;
        droptop(i, 0, k)
        {
            nxtsw[i] = max(nxtsw[i], tab[id][i]);
        }

        if (comp(dp[ss], nxtsw)) {
            dp[ss] = nxtsw;
            dfs(ss, cur + 1, nxtsw);
        }
    }
}

int f() {
    cin >> n >> m >> d >> k;
    if (k == 1) {
        fk1();
        return false;
    }
    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb({b, i}), wec[b].pb({a, i});
        droptop(j, 0, k)
        {
            cin >> tab[i][j];
        }
    }

    vector<int> sw(k);
    dfs(1, 0, sw);

    // cout << dp[5][0] << " " << dp[5][1] << endl;
    droptop(i, 0, k)
    {
        cout << dp[n][i] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
