/*
Now playing:
Juice WRLD - Cavalier [The Pre-Party (Extended)]
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

map<pair<int, int>, int> mapa;
vector<int> wec[200'001];
vector<int> color[200'001];
int dep[200'001];
int up[200'001][20];
int pref[200'001];

void dfs1(int w = 0, int p = 0) {
    up[w][0] = p;
    droptop(i, 1, 20)
    {
        up[w][i] = up[up[w][i - 1]][i - 1];
    }
    for (int ss : wec[w]) {
        if (ss != p) {
            dep[ss] = dep[w] + 1;
            dfs1(ss, w);
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b]) {
            a = up[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int res = 0;
int dfs(int w = 0, int p = -1) {
    int cur = pref[w];
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        cur += dfs(ss, w);
    }
    if (w != 0 && cur == 0) {
        res++;
    }
    return cur;
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        int col = 0;
        droptop(i, 0, n - 2)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            col = max(col, d);
            color[d].pb(i);

            if (a > b)
                swap(a, b);
            if (a > c)
                swap(a, c);
            if (b > c)
                swap(b, c);

            if (mapa.count({a, b}))
                wec[mapa[{a, b}]].pb(i), wec[i].pb(mapa[{a, b}]);
            else
                mapa[{a, b}] = i;

            if (mapa.count({a, c}))
                wec[mapa[{a, c}]].pb(i), wec[i].pb(mapa[{a, c}]);
            else
                mapa[{a, c}] = i;

            if (mapa.count({b, c}))
                wec[mapa[{b, c}]].pb(i), wec[i].pb(mapa[{b, c}]);
            else
                mapa[{b, c}] = i;
        }

        if (n - 2 > 0) {
            dfs1(0, 0);
        }

        droptop(i, 1, col + 1)
        {
            if (color[i].empty())
                continue;
            int cur = color[i][0];
            droptop(j, 1, color[i].size())
            {
                cur = lca(cur, color[i][j]);
            }

            for (int ss : color[i]) {
                pref[ss]++;
            }
            pref[cur] -= color[i].size();
        }

        if (n - 2 > 0) {
            dfs(0, -1);
        }
        cout << res;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
