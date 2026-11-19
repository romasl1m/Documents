/*
Now playing:
Juice WRLD - The Party Never Ends [The Party Never Ends 2.0]
*/
#include <pthread.h>
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

struct node {
    int l, r, cnt;
} tree[50'001];
int cnt = 0;
int root[50'001];

int upd(int w, int l, int r, int war) {
    int cur = ++cnt;
    tree[cur] = tree[w], tree[cur].cnt++;
    if (l == r)
        return cur;

    int mid = l + ((r - l) >> 1);
    if (war <= mid)
        tree[cur].l = upd(tree[w].l, l, mid, war);
    else
        tree[cur].r = upd(tree[w].r, mid + 1, r, war);
    return cur;
}

int query(int ssroot, int wroot, int lr, int rr, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = l + ((r - l) >> 1);
    int lcnt = tree[tree[ssroot].l].cnt + tree[tree[wroot].l].cnt - tree[tree[lr].l].cnt - tree[tree[rr].l].cnt;

    if (k <= lcnt)
        return query(tree[ssroot].l, tree[wroot].l, tree[lr].l, tree[rr].l, l, mid, k);
    return query(tree[ssroot].r, tree[wroot].r, tree[lr].r, tree[rr].r, mid + 1, r, k - lcnt);
}

void dfs(int w, int p, const vector<pair<int, int>> *wec, int lca[][20], int *dep) {
    lca[w][0] = p;
    droptop(i, 1, 20)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }

    for (auto [ss, cost] : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w, wec, lca, dep);
    }
}

int lift(int a, int dif, int lca[][20]) {
    cookie(i, 19, 0)
    {
        if (dif & (1 << i))
            a = lca[a][i];
    }
    return a;
}

int lcaf(int a, int b, int lca[][20], const int *dep) {
    if (dep[a] < dep[b])
        swap(a, b);
    a = lift(a, dep[a] - dep[b], lca);
    if (a == b)
        return a;

    cookie(i, 19, 0)
    {
        if (lca[a][i] != lca[b][i] and lca[a][i] != 0)
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

int f() {
    int n;
    cin >> n;
    static vector<pair<int, int>> wec[50'001];
    static int lca[50'001][20];
    static int dep[50'001];
    droptop(i, 1, n + 1)
    {
        wec[i].clear();
    }
    vector<tuple<int, int, int>> edges(n - 1);
    vector<int> weights(n - 1);
    droptop(i, 1, n)
    {
        root[i] = dep[i] = 0;
        int a, b, c;
        cin >> a >> b >> c;
        wec[a].pb({b, c}), wec[b].pb({a, c});
        edges[i - 1] = {a, b, c};
    }
    root[n] = dep[n] = 0;
    tree[0] = {false, false, false};

    dep[1] = 1;
    dfs(1, 0, wec, lca, dep);

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
