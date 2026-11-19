/*
Now playing:
Offset - Red Room [FATHER OF 4]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <queue>
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

void dfsdist(int w, const vector<vector<int>> &wec, vector<int> &dist) {
    queue<int> q;
    q.push(1);
    while (not q.empty()) {
        int w = q.front();
        q.pop();
        for (int ss : wec[w]) {
            if (dist[ss] == 1e9)
                dist[ss] = dist[w] + 1, q.push(ss);
        }
    }
}

bool wiz[200'001];
void dfs(int w, const vector<vector<int>> &wec, const vector<int> &dist, vector<int> &low) {
    low[w] = dist[w], wiz[w] = true;
    for (int ss : wec[w]) {
        if (not wiz[ss] and dist[ss] > dist[w])
            dfs(ss, wec, dist, low);

        if (dist[w] < dist[ss])
            low[w] = min(low[w], low[ss]);
        else
            low[w] = min(low[w], dist[ss]);
    }
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 1, n + 1)
    {
        wiz[i] = false;
    }
    vector<vector<int>> wec(n + 1);
    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b);
    }

    vector<int> dist(n + 1, 1e9), low(n + 1);
    dist[1] = 0;
    dfsdist(1, wec, dist);
    dfs(1, wec, dist, low);

    droptop(i, 1, n + 1)
    {
        cout << low[i] << " ";
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
