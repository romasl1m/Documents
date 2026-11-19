/*
Now playing:
Lil Peep - cobain [HELLBOY]
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
#define int ll

vector<pair<int, int>> wec[100'001];
vector<int> col[100'001];
int lca[100'001][18];
int dep[100'001];
int dist[100'001];

void dfs(int w, int p) {
    lca[w][0] = p;
    droptop(i, 1, 18)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }

    for (auto [ss, cost] : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1, dist[ss] = dist[w] + cost;
        dfs(ss, w);
    }
}

int lift(int a, int dif) {
    for (int i = 17; i >= 0; i--) {
        if (dif & (1 << i)) {
            a = lca[a][i];
        }
    }
    return a;
}

int lcaf(int a, int b) {
    if (dep[b] > dep[a])
        swap(a, b);
    a = lift(a, dep[a] - dep[b]);

    if (a == b)
        return a;
    for (int i = 17; i >= 0; i--) {
        if (lca[a][i] != 0 and lca[b][i] != lca[a][i])
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

int distf(int a, int b) {
    int p = lcaf(a, b);
    return dist[a] + dist[b] - (dist[p] << 1);
}

int rest(int x, int a, int b) {
    return distf(a, x) + distf(b, x);
}

void f() {
    int n, rmks;
    cin >> n >> rmks;
    droptop(i, 1, n + 1)
    {
        int x;
        cin >> x;
        col[x].pb(i);
    }

    droptop(i, 1, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        wec[a].pb({b, c}), wec[b].pb({a, c});
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int a, b, r;
        cin >> a >> b >> r;

        if (rmks == 1) {

            cout << (col[r].empty() ? -1 : distf(a, b)) << "\n";
            continue;
        }

        int cur = 1e18;
        for (int x : col[r]) {
            cur = min(cur, rest(x, a, b));
        }

        cout << (cur == 1e18 ? -1 : cur) << "\n";
    }
}

signed main() {
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
