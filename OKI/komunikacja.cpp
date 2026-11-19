/*
Now playing:
Juice WRLD - Starstruck [Starstruck]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
vector<int> wec[30'001];
int lca[30'001][16];
int dep[30'001];

void dfs(int w, int p = 0) {
    lca[w][0] = p;
    for (int i = 1; i < 16; i++) {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w);
    }
}
int lift(int x, int dif) {
    droptop(0, 16)
    {
        if (dif & (1 << i)) {
            x = lca[x][i];
        }
    }
    return x;
}
int lcaf(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    a = lift(a, dep[a] - dep[b]);
    if (a == b)
        return a;
    for (int i = 15; i >= 0; i--) {
        if (lca[a][i] != lca[b][i] and lca[a][i] != 0 and lca[b][i] != 0) {
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            wec[b].pb(a);
        }
        dfs(1);
        int res = 0;
        int m;
        cin >> m;
        int last = 1;
        cookie(m)
        {
            int x;
            cin >> x;
            int cur = lcaf(x, last);
            res += -(dep[cur] << 1) + dep[last] + dep[x];
            last = x;
        }
        cout << res;
    }
    return 0;
}
