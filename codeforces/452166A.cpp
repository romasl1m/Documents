/*
Now playing:
Juice WRLD - Fast [Death Race For Love (Bonus Track Version)]
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

vector<int> wec[300'001];
int par[300'001];
int dep[300'001];
int siz[300'001];
int heavy[300'001];
int pos[300'001];
int head[300'001];
int tab[300'001];

const int base = 300'001;
ll tree[base << 1];

void add(int w, int x) {
    w += base;
    tree[w] = x;
    w >>= 1;
    while (w > 0) {
        tree[w] = tree[w << 1] + tree[w << 1 | 1];
        w >>= 1;
    }
}

ll query(int l, int r) {
    ll res = 0;
    l += base, r += base;

    while (l <= r) {
        if (l & 1)
            res += tree[l++];
        if (not(r & 1))
            res += tree[r--];

        l >>= 1, r >>= 1;
    }
    return res;
}

void dfs(int w, int p) {
    heavy[w] = -1, siz[w] = 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        par[ss] = w, dep[ss] = dep[w] + 1;
        dfs(ss, w);

        siz[w] += siz[ss];
        if (heavy[w] == -1 or siz[ss] > siz[heavy[w]])
            heavy[w] = ss;
    }
}

int curpos = 0;
void decompose(int w, int h) {
    head[w] = h;
    pos[w] = curpos++;

    if (heavy[w] != -1)
        decompose(heavy[w], h);

    for (int ss : wec[w]) {
        if (ss == par[w] or ss == heavy[w])
            continue;
        decompose(ss, ss);
    }
}

ll hldquery(int w, int ss) {
    ll res = 0;
    while (head[w] != head[ss]) {
        if (dep[head[w]] < dep[head[ss]])
            swap(w, ss);

        res += query(pos[head[w]], pos[w]);
        w = par[head[w]];
    }

    if (dep[w] > dep[ss])
        swap(w, ss);

    res += query(pos[w], pos[ss]);
    return res;
}

void f() {
    int n, q;
    cin >> n >> q;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0), decompose(1, 0);

    droptop(i, 1, n + 1)
    {
        add(pos[i], tab[i]);
    }

    while (q--) {
        int t, w, x;
        cin >> t >> w >> x;

        if (t == 1) {
            add(pos[w], x);
        } else {
            cout << hldquery(w, x) << "\n";
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
