/*
Now playing:
Huncho Jack - Saint Laurent Mask [Huncho Jack, Jack Huncho]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[200'001];
int in[200'001], out[200'001];
int dep[200'001];
int lca[200'001][19];
ll int res[200'001];
int col[200'001];
int chose[200'001];
int cnt[200'001];
vector<int> colwec[200'001];
int inout = 0;

bool comp(int a, int b) {
    return in[a] < in[b];
}
bool comp2(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

void dfs(int w, int p) {
    lca[w][0] = p, in[w] = ++inout;
    droptop(i, 1, 19)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w);
    }
    out[w] = ++inout;
}

bool earlier(int a, int b) {
    return in[a] <= in[b] and out[b] <= out[a];
}

int lift(int a, int x) {
    for (int i = 18; i >= 0; i--)
        if (x & (1 << i))
            a = lca[a][i];
    return a;
}

int lcaf(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    a = lift(a, dep[a] - dep[b]);

    if (a == b)
        return a;

    for (int i = 18; i >= 0; i--) {
        if (lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    }

    return lca[a][0];
}

void f() {
    int n;
    cin >> n;
    inout = 0;
    droptop(i, 1, n + 1)
    {
        colwec[i].clear(), wec[i].clear(), res[i] = -1;
        droptop(j, 0, 19)
        {
            lca[i][j] = 0;
        }
    }
    droptop(i, 1, n + 1)
    {
        cin >> col[i];
        colwec[col[i]].pb(i);
    }
    droptop(i, 1, n + 1)
    {
        cin >> chose[i];
    }

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0);

    droptop(i, 1, n + 1)
    {
        if (colwec[i].empty())
            continue;
        int m = colwec[i].size(), siz = chose[i];

        vector<int> cur = colwec[i];
        hotbox(cur);

        int sz = cur.size();
        droptop(j, 0, sz - 1)
        {
            cur.pb(lcaf(cur[j], cur[j + 1]));
        }

        hotbox(cur);
        cur.erase(unique(cur.begin(), cur.end()), cur.end());

        for (int ss : colwec[i])
            cnt[ss] = 1;

        stack<int> s;
        vector<pair<int, int>> tree;
        for (int x : cur) {
            while (not s.empty() and not earlier(s.top(), x))
                s.pop();
            if (not s.empty())
                tree.pb({s.top(), x}); // s is top slime of x in color i
            s.push(x);
        }

        vector<pair<ll, ll>> roads;
        ll dist = 0;

        for (int j = tree.size() - 1; j >= 0; j--) {
            auto [p, w] = tree[j];
            cnt[p] += cnt[w];

            ll minhalf = min(cnt[w], m - cnt[w]),
               len = dep[w] - dep[p];

            dist += len * minhalf, roads.pb({minhalf, len});
        }

        // hotbox(roads, false);
        sort(roads.begin(), roads.end(), comp2);

        ll chosen = 0, need = siz - 1;
        for (const auto &[minhalf, len] : roads) {
            ll cur = min(need, len);
            chosen += cur * minhalf,
                need -= cur;
            if (need == 0)
                break;
        }

        res[i] = dist - chosen;
        for (int ss : cur)
            cnt[ss] = 0;
    }

    droptop(i, 1, n + 1)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
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
