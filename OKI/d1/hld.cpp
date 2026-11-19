/*
Now playing:
Future - Hard Work Pays Off [Future and Juice WRLD Present... WRLD ON DRUGS]
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
int par[100'001], dep[100'001], sub[100'001], heavy[100'001], pos[100'001], head[100'001];

void dfs(int w = 1, int p = -1) {
    heavy[w] = -1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;

        par[ss] = w;
        dep[ss] = dep[w] + 1;
        dfs(ss, w);
        sub[w] += sub[ss];

        if (heavy[w] == -1 or sub[ss] > sub[heavy[w]])
            heavy[w] = ss;
    }
}

int heavypos = 0;
void hld(int w, int h) {
    head[w] = h, pos[w] = heavypos++;
    if (heavy[w] != -1) {
        hld(heavy[w], h);
    }

    for (int ss : wec[w]) {
        if (ss == par[w] or ss == heavy[w])
            continue;
        hld(ss, ss);
    }
}

int up[18][100'001];
void build(int n) {
    droptop(i, 1, n + 1)
    {
        up[0][i] = par[i];
    }

    droptop(i, 1, 19)
    {
        droptop(j, 1, n + 1)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}

int lift(int w, int k) {
    droptop(i, 0, 19)
    {
        if (k & (1 << i))
            w = up[i][w];
    }
    return w;
}

bool przodek(int a, int b) {
    return pos[a] <= pos[b] and pos[b] < pos[a] + sub[a];
}

vector<pair<int, int>> side(int w, int ss, int n) {
    vector<pair<int, int>> res;
    if (not przodek(w, ss)) {
        int l = pos[w] + 1, r = pos[w] + sub[w];
        res.pb({l, r});
        return res;
    }

    int dif = dep[ss] - dep[w], c = lift(ss, dif - 1);
    int cl = pos[c] + 1, cr = pos[c] + sub[c];

    if (cl > 1)
        res.pb({1, cl - 1});
    if (cr < n)
        res.pb({cr + 1, n});
    return res;
}

const int base = 100'001;
int tree[base << 1], lt[base << 1], rt[base << 1];

int nodes = 0;
int upd(int old, int l, int r, int p) {
    int cur = ++nodes;

    lt[cur] = lt[old];
    rt[cur] = rt[old];
    tree[cur] = tree[old] + 1;

    if (l == r)
        return cur;
    int mid = l + ((r - l) >> 1);

    if (p <= mid)
        lt[cur] = upd(lt[old], l, mid, p);
    else
        rt[cur] = upd(rt[old], mid + 1, r, p);

    return cur;
}

int query(int a, int b, int l, int r, int x, int y) {
    if (x <= l and r <= y)
        return tree[a] - tree[b];
    if (r < x or y < l)
        return 0;
    int mid = l + ((r - l) >> 1);

    return query(lt[a], lt[b], l, mid, x, y) + query(rt[a], rt[b], mid + 1, r, x, y);
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }

        dep[1] = 0, dfs(1, 0), hld(1, 1), build(n);

        int m;
        cin >> m;
        vector<vector<int>> ys(n + 1);

        droptop(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            int x = pos[a] + 1, y = pos[b] + 1;

            if (x > y)
                swap(x, y);
            ys[x].pb(y);
        }

        vector<int> root(n + 1);
        droptop(i, 1, n + 1)
        {
            root[i] = root[i - 1];
            for (int ss : ys[i]) {
                root[i] = upd(root[i], 1, n, ss);
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;

            if (a == b) {
                cout << "1\n";
                continue;
            }

            vector<pair<int, int>> x = side(a, b, n), y = side(b, a, n);
            cout <<
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
