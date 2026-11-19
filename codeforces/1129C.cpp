/*
Now playing:
Linkin Park - Runaway [Hybrid Theory]
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

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &dist) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dist[ss] = dist[w] + 1, dfs(ss, w, wec, dist);
    }
}

int cur = 0;
void inout(int w, int p, const vector<vector<int>> &wec, vector<int> &in, vector<int> &out) {
    in[w] = cur++;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        inout(ss, w, wec, in, out);
    }
    out[w] = cur;
}

int f() {
    int n, m;
    cin >> n >> m;
    cur = 0;
    vector<vector<int>> wec(n + 1);
    vector<int> dist(n + 1), in(n + 1), out(n + 1);
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(n, 0, wec, dist), inout(1, 0, wec, in, out);
    int res = dist[1];
    int type = 0;
    for (int ss : wec[1]) {
        if (in[ss] <= in[n] and in[n] < out[ss])
            type = ss;
    }
    droptop(i, 0, m)
    {
        int x;
        cin >> x;
        if (in[type] <= in[x] and in[x] < out[type])
            res = max(res, 1 + dist[x]);
    }
    cout << res;
    return 0;
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
