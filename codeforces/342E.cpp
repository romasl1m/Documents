/*
Now playing:
Trippie Redd - Say What (feat. PARTYNEXTDOOR) [NDA]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[100'001];
int par[100'001];
int lca[100'001][18];
int dep[100'001];
int best[100'001];
int sub[100'001];
bool wiz[100'001];

void dfs(const int &w, const int &p) {
    lca[w][0] = p, sub[w] = 1;
    droptop(i, 1, 18)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }

    for (const int &ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1, dfs(ss, w);
        sub[w] += sub[ss];
    }
}

void subcnt(const int &w, const int &p) {
    sub[w] = 1;
    for (const int &ss : wec[w]) {
        if (ss == p or wiz[ss])
            continue;
        subcnt(ss, w);
        sub[w] += sub[ss];
    }
}

int lift(int x, const int &dif) {
    for (int i = 17; i >= 0; i--) {
        if (dif & (1 << i)) {
            x = lca[x][i];
        }
    }
    return x;
}
int lcaf(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    b = lift(b, dep[b] - dep[a]);

    if (a == b)
        return a;

    for (int i = 17; i >= 0; i--) {
        if (lca[a][i] > 0 and lca[a][i] != lca[b][i]) {
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}

int dist(const int &a, const int &b) {
    const int &lcaw = lcaf(a, b);
    return dep[a] + dep[b] - (dep[lcaw] << 1);
}

void upd(const int &x) {
    int cur = x;
    while (cur > 0) {
        best[cur] = min(best[cur], dist(cur, x));
        cur = par[cur];
    }
}

int query(const int &w) {
    int res = 2e9;
    int cur = w;
    while (cur > 0) {
        res = min(res, best[cur] + dist(w, cur));
        cur = par[cur];
    }
    return res;
}

int centroid(const int &w, const int &p, const int &total) {
    for (const int &ss : wec[w]) {
        if (ss == p or wiz[ss])
            continue;
        if (sub[ss] > (total >> 1))
            return centroid(ss, w, total);
    }
    return w;
}

void partition(const int &w, const int &p) {
    subcnt(w, 0);
    const int &cur = centroid(w, 0, sub[w]);

    wiz[cur] = true;
    par[cur] = p;

    for (const int &ss : wec[cur]) {
        if (wiz[ss])
            continue;
        partition(ss, cur);
    }
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    droptop(i, 1, n + 1)
    {
        best[i] = 2e9;
    }

    dfs(1, 0), partition(1, 0), upd(1);

    while (m--) {
        int cur, x;
        cin >> cur >> x;
        if (cur == 1) {
            upd(x);
        } else {
            cout << query(x) << "\n";
        }
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
