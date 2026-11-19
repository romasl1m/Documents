#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[200'001];
int lca[200'001][20];
int dep[200'001];
void dfs(int w, int p = -1) {
    lca[w][0] = p;
    for (int i = 1; i < 20; i++) {
        if (lca[w][i - 1] == -1) {
            lca[w][i] = -1;
            continue;
        }
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w);
    }
}
int lift(int a, int depth) {
    return 0;
}
int fin(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    a = lift(a, dep[a] - dep[b]);
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--) {
        if (lca[a][i] == -1 or lca[b][i] == -1 or lca[b][i] == lca[a][i])
            continue;
        a = lca[a][i];
        b = lca[b][i];
    }
    return lca[a][0];
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        wec[a].push_back(b), wec[b].push_back(a);
    }
    while (m--) {
        int k;
        cin >> k;
        bool ok = true;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
        }
    }
}
