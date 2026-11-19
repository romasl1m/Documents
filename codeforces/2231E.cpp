/*
Now playing:
Otsochodzi - GIŃ ZA MNIE [RIOTT]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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

int dfs(int w, int p, int d, const vector<vector<int>> &wec, vector<int> &dep) {
    int maks1 = d, maks2 = d;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        int cur = dfs(ss, w, d + 1, wec, dep);
        if (cur > maks1)
            maks2 = maks1, maks1 = cur;
        else if (cur > maks2)
            maks2 = cur;
    }

    int cur = min(maks2, maks1) - 1;
    if (cur >= 0)
        dep[cur] = max(dep[cur], maks1 + maks2 - (d << 1) + 1);
    return maks1;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> dep(n + 1);

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    int res = 0,
        maks = dfs(1, 0, 0, wec, dep);
    cookie(i, n - 1, 0)
    {
        dep[i] = max(dep[i], dep[i + 1]);
    }

    droptop(i, 1, n + 1)
    {
        while (res < maks and i + (dep[res] >> 1) > res)
            res++;
        cout << res << " ";
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
