/*
Now playing:
Travis Scott - Can't Feel Myself (feat. Playboi Carti, Lil Uzi Vert) [Can't Feel Myself]
*/
#include <cinttypes>
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

const int base = 2e5;
int tab[base + 5];
int leaf[base + 5];
vector<pair<int, int>> tree[base * 5 + 10];
int in[base * 5 + 10], pos[base * 5 + 10], total, dist[base * 5 + 5];
bool wiz[base * 5 + 10];

void build(int w, int l, int r) {
    wiz[w] = true, total++;
    if (l == r) {
        leaf[l] = w, pos[w] = l;
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(w << 1, l, mid), build(w << 1 | 1, mid + 1, r);
    tree[w << 1].pb({w, 0}), tree[w << 1 | 1].pb({w, 0});
}

void query(int w, int l, int r, int a, int b, int m) {
    if (a > b or b < l or a > r)
        return;
    if (a <= l and r <= b) {
        tree[w].pb({m, 0});
        return;
    }
    int mid = l + ((r - l) >> 1);
    query(w << 1, l, mid, a, b, m), query(w << 1 | 1, mid + 1, r, a, b, m);
}

int f() {
    int n, s, m;
    cin >> n >> s >> m;
    droptop(i, 0, s)
    {
        int x, y;
        cin >> x >> y;
        tab[x] = y;
    }
    build(1, 1, n);
    droptop(i, 0, m)
    {
        int l, r, k;
        cin >> l >> r >> k;
        vector<int> cur(k);
        for (int &x : cur) {
            cin >> x;
        }
        sort(hotbox(cur));

        int war = (n << 2) + 1 + i, lst = l;
        wiz[war] = true, total++;
        for (int &x : cur) {
            query(1, 1, n, lst, x - 1, war),
                tree[war].pb({leaf[x], 1}),
                lst = x + 1;
        }
        query(1, 1, n, lst, r, war);
    }

    int war = (n << 2) + m + 1;
    droptop(w, 1, war + 1)
    {
        if (not wiz[w])
            continue;
        for (const auto &[ww, ss] : tree[w]) {
            in[ww]++;
        }
    }
    droptop(i, 1, n + 1)
    {
        dist[leaf[i]] = 1;
    }

    vector<int> q;
    droptop(w, 1, war + 1)
    {
        if (wiz[w] and not in[w])
            q.pb(w);
    }

    droptop(i, 0, q.size())
    {
        int w = q[i];
        if (pos[w]) {
            int x = pos[w];
            if (tab[x]) {
                if (dist[w] > tab[x])
                    cout << "NIE", exit(0);
                dist[w] = tab[x];
            }
            if (dist[w] > 1e9)
                cout << "NIE", exit(0);
        }
        for (const auto [ww, ss] : tree[w]) {
            dist[ww] = max(dist[ww], dist[w] + ss);
            if (not --in[ww])
                q.pb(ww);
        }
    }
    if (q.size() < total)
        cout << "NIE", exit(0);
    cout << "TAK\n";
    droptop(i, 1, n + 1)
    {
        cout << dist[leaf[i]] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
