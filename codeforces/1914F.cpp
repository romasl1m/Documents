/*
Now playing:
Offset - Something I Need [Something I Need]
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
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &siz) {
    siz[w] = 1;
    for (int ss : wec[w]) {
        // if (ss == p)
        //     continue;
        dfs(ss, w, wec, siz);
        siz[w] += siz[ss];
    }
}

int dfs0(int w, int cur, const vector<vector<int>> &wec, const vector<int> &sub) {
    // cerr << w << " " << cur << endl;
    if (wec[w].empty())
        return 0;
    int sum = 0, maks = 0;
    for (int ss : wec[w]) {
        sum += sub[ss];
        if (sub[maks] < sub[ss])
            maks = ss;
    }

    if (sub[maks] - cur <= sum - sub[maks])
        return (sum - cur) >> 1;
    return sum - sub[maks] + dfs0(maks, max(cur + sum - sub[maks] - 1, 0), wec, sub);
}

int f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> sub(n + 1);

    droptop(i, 2, n + 1)
    {
        int x;
        cin >> x;
        wec[x].pb(i);
    }
    dfs(1, 0, wec, sub);
    return dfs0(1, 0, wec, sub);
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << f();
        cout << "\n";
    }
    return 0;
}
