/*
Now playing:
Lil Uzi Vert - Two® [Luv Is Rage 2]
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

bool black[200'001];
void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &dist, int &res) {
    if (black[w])
        res = min(res, dist[w]);
    if (dist[w] >= res)
        return;

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        if (dist[ss] > dist[w] + 1)
            dist[ss] = dist[w] + 1, dfs(ss, w, wec, dist, res);
        else
            res = min(res, dist[w] + dist[ss] + 1);
    }
}

void f() {
    int n, k;
    cin >> n >> k;

    vector<int> tab(n - 1), dist(n + 1);
    vector<vector<int>> wec(n + 1);
    droptop(i, 0, n - 1)
    {
        cin >> tab[i];
    }
    droptop(i, 1, n + 1)
    {
        black[i] = false;
        dist[i] = 2e9;
    }
    dist[k] = false;

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    int res = 2e9;
    dfs(k, 0, wec, dist, res), black[k] = true;

    droptop(i, 0, n - 1)
    {
        dist[tab[i]] = false, dfs(tab[i], 0, wec, dist, res), black[tab[i]] = true;
        cout << res << " ";
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
