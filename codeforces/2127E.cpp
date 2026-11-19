/*
Now playing:
Linkin Park - Stained [From Zero (Deluxe Edition)]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[200'001], col[200'001];
int cur = 0;
int color[200'001], weight[200'001], cnt[200'001], nxtcol[200'001];
bool ok[200'001], wiz[200'001];
int lca[200'001][18], dep[200'001], in[200'001];
bool comp(int a, int b) {
    return in[a] < in[b];
}

void dfs(int w, int p) {
    in[w] = cur++, lca[w][0] = p;
    droptop(i, 1, 18)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1, lca[ss][0] = w;
        dfs(ss, w);
    }
}

int lift(int a, int dif) {
    cookie(i, 17, 0)
    {
        if (dif & (1 << i))
            a = lca[a][i];
    }
    return a;
}

int lcaf(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    a = lift(a, dep[a] - dep[b]);
    if (a == b)
        return a;

    cookie(i, 17, 0)
    {
        if (lca[a][i] != lca[b][i] and lca[a][i] != 0)
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

void colorf(int w, int p, int colour) {
    if (color[w] > 0)
        colour = color[w];
    else
        color[w] = colour;

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        colorf(ss, w, colour);
    }
}

void f() {
    int n, k;
    cin >> n >> k;
    cur = 0;
    droptop(i, 1, n + 1)
    {
        wiz[i] = nxtcol[i] = cnt[i] = color[i] = ok[i] = false, wec[i].clear(), col[i].clear();
    }
    droptop(i, 1, n + 1)
    {
        cin >> weight[i];
    }
    droptop(i, 1, n + 1)
    {
        cin >> color[i];
        if (color[i] > 0)
            col[color[i]].pb(i);
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    bool possible = false;
    droptop(i, 1, n + 1)
    {
        if (color[i] > 0) {
            possible = true;
            break;
        }
    }
    if (not possible) {
        cout << "0\n";
        droptop(i, 0, n)
        {
            cout << "1 ";
        }
        cout << "\n";
        return;
    }
    dfs(1, 0);

    droptop(i, 1, k + 1)
    {
        hotbox(col[i]);
        vector<int> cur;

        droptop(j, 0, (int)col[i].size() - 1)
        {
            int w = col[i][j], ss = col[i][j + 1], curlca = lcaf(w, ss);
            if (wiz[curlca])
                continue;

            if (color[curlca] > 0) {
                if (color[curlca] != i) {
                    ok[curlca] = true;
                }
                continue;
            }

            nxtcol[curlca] = i;
            cnt[curlca]++;
            wiz[curlca] = true;
            cur.pb(curlca);
        }

        col[i].clear();
        for (int x : cur) {
            wiz[x] = false;
        }
    }

    ll res = 0;
    droptop(i, 1, n + 1)
    {
        if (ok[i] or cnt[i] > 1)
            res += weight[i];
        if (cnt[i] == 1 and color[i] == 0)
            color[i] = nxtcol[i];
    }

    cout << res << "\n";
    droptop(i, 1, n + 1)
    {
        if (color[i] > 0) {
            colorf(1, 0, color[i]);
            break;
        }
    }

    droptop(i, 1, n + 1)
    {
        cout << color[i] << " ";
    }
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
