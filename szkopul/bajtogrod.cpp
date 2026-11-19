/*
Now playing:
Otsochodzi - SŁOWA BOLĄ [RIOTT]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// bool comp(int a, int b) {
//     return a < b;
// }
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

vector<pair<int, char>> wec[2'001];
vector<pair<int, int>> roadsw[4'000'001];

int trie[4'000'001][26];
bool endt[4'000'001];
int siz = 1;

int lca[2'001][12];
int dep[2'001];

void dfs1(int w, int p) {
    droptop(i, 1, 12)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }
    for (auto &[ss, c] : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1, lca[ss][0] = w;
        dfs1(ss, w);
    }
}

int lift(int b, int dif) {
    cookie(i, 11, 0)
    {
        if (dif & (1 << i))
            b = lca[b][i];
    }
    return b;
}

int lcaf(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    b = lift(b, dep[b] - dep[a]);
    if (a == b)
        return a;

    cookie(i, 11, 0)
    {
        if (lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

int ins(int w, char c) {
    int x = c - 'A';
    if (not trie[w][x])
        trie[w][x] = ++siz;
    return trie[w][x];
}

void dfs0(int start, int w, int p, int cur) {
    if (w != start)
        roadsw[cur].pb({start, w});
    for (const auto &[ss, c] : wec[w]) {
        if (ss == p)
            continue;
        int nxt = ins(cur, c);
        dfs0(start, ss, w, nxt);
    }
}

int pref[2'001];
int check(int w, int p, bool &ok) {
    int cur = pref[w];
    for (auto &[ss, c] : wec[w]) {
        if (ss == p)
            continue;
        int sscur = check(ss, w, ok);
        if (not sscur)
            ok = false;
        cur += sscur;
    }
    return cur;
}

bool covers(int idx, int len, const int &n) {
    if ((ll)roadsw[idx].size() * len < n - 1)
        return false;

    droptop(i, 1, n + 1)
    {
        pref[i] = 0;
    }

    for (const auto &[a, b] : roadsw[idx]) {
        int w = lcaf(a, b);
        pref[w] -= 2, pref[a]++, pref[b]++;
    }

    bool ok = true;
    check(1, 0, ok);
    return ok;
}

vector<string> res;
string curs = "";

void fstrings(int w, int len, const int &n) {
    if (w != 1 and covers(w, len, n))
        res.pb({curs});

    droptop(i, 0, 26)
    {
        if (trie[w][i]) {
            curs.pb('A' + i), fstrings(trie[w][i], len + 1, n), curs.pop_back();
        }
    }
}

int f() {
    int n;
    cin >> n;
    droptop(i, 1, n)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        wec[a].pb({b, c}), wec[b].pb({a, c});
    }

    dfs1(true, false);
    droptop(i, 1, n + 1)
    {
        dfs0(i, i, false, true);
    }

    fstrings(true, false, n);
    hotbox(res);
    cout << res.size() << "\n";
    droptop(i, 0, res.size())
    {
        cout << res[i] << "\n";
    }

    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
