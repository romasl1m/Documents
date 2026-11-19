/*
Now playing:
Bring Me The Horizon - sTraNgeRs [POST HUMAN: NeX GEn]
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
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

ll color[100'001][3];
vector<vector<int>> wec;
vector<int> col;

void dfs(int w, int p) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        col[ss] = 3 - col[w] - col[p];
        dfs(ss, w);
    }
}

int f() {
    int n;
    cin >> n;
    wec.assign(n + 1, vector<int>());
    col.assign(n + 1, -1);

    droptop(i, 1, n + 1)
    {
        cin >> color[i][0];
    }
    droptop(i, 1, n + 1)
    {
        cin >> color[i][1];
    }
    droptop(i, 1, n + 1)
    {
        cin >> color[i][2];
    }

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    droptop(i, 1, n + 1)
    {
        if (wec[i].size() > 2) {
            cout << -1;
            return false;
        }
    }

    vector<int> res;
    ll minres = 1e18;
    int a = wec[1][0];

    droptop(i, 0, 3)
    {
        droptop(j, 0, 3)
        {
            if (i == j)
                continue;

            droptop(k, 1, n + 1)
            {
                col[k] = -1;
            }

            col[1] = i;
            col[a] = j;
            dfs(a, 1), dfs(1, a);
            ll cur = 0;
            droptop(k, 1, n + 1)
            {
                cur += color[k][col[k]];
            }

            if (cur < minres) {
                minres = cur;
                res = col;
            }
        }
    }

    cout << minres << "\n";
    droptop(i, 1, n + 1)
    {
        cout << res[i] + 1 << " ";
    }
    return true;
}

signed main() {
    raindrop;
    int t = 1;
    // cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
