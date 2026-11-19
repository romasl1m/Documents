/*
Now playing:
MORGENSHTERN - CCTV [LAST ONE]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

struct rd {
    int w, war, id;
    bool operator>(const rd &other) const {
        return war > other.war;
    }
};
struct st {
    int a, b, war;
};

vector<rd> wec[200'001];
vector<pair<int, int>> mst[200'001];
st path[200'001];
bool wiz[200'001];
// ll dist[200'001];
bool inmst[200'001];

ll mstf(const int &n) {
    ll res = 0;
    int cnt = 0;

    wiz[1] = true;
    priority_queue<rd, vector<rd>, greater<rd>> q;
    for (const auto &ss : wec[1]) {
        q.push(ss);
    }

    while (not q.empty() and cnt < n - 1) {
        const auto [w, war, id] = q.top();
        q.pop();
        if (wiz[w])
            continue;

        wiz[w] = true, inmst[id] = true;
        res += war, cnt++;

        const int &from = (path[id].a == w) ? path[id].b : path[id].a;
        mst[from].pb({w, war}), mst[w].pb({from, war});

        for (const auto &ss : wec[w]) {
            if (wiz[ss.w])
                continue;
            q.push(ss);
        }
    }
    return res;
}

int dep[200'001];
int lca[200'001][20];
int maks[200'001][20];

void dfs(const int &w, const int &p, const int &cur) {
    lca[w][0] = p;
    maks[w][0] = cur;

    droptop(i, 1, 20)
    {
        int par = lca[w][i - 1];
        if (par != 0) {
            lca[w][i] = lca[par][i - 1];
            maks[w][i] = max(maks[w][i - 1], maks[par][i - 1]);
        } else {
            lca[w][i] = 0;
            maks[w][i] = maks[w][i - 1];
        }
    }

    for (const auto &[ss, war] : mst[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w, war);
    }
}

int lift(int &w, const int &dif) {
    int res = 0;
    for (int i = 19; i >= 0; i--) {
        if (dif & (1 << i)) {
            res = max(res, maks[w][i]),
            w = lca[w][i];
        }
    }
    return res;
}
int maksf(int a, int b) {
    int res = 0;
    if (dep[a] < dep[b])
        swap(a, b);

    res = max(lift(a, dep[a] - dep[b]), res);

    if (a == b)
        return res;

    for (int i = 19; i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            res = max({res, maks[a][i], maks[b][i]}),
            a = lca[a][i], b = lca[b][i];
        }
    }

    return max({res, maks[a][0], maks[b][0]});
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        wec[b].pb({a, c, i});
        wec[a].pb({b, c, i});
        path[i] = {a, b, c};
    }

    const ll cost = mstf(n);

    dfs(1, 0, 0);

    droptop(i, 0, m)
    {
        cout << (inmst[i] ? cost : cost - maksf(path[i].a, path[i].b) + path[i].war) << "\n";
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
