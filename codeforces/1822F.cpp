/*
Now playing:
Otsochodzi - NIENAWIDZĘ WARSZAWY [RIOTT]
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
#define int ll

int f() {
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> wec(n + 1);
    vector<int> dist1(n + 1), dist2(n + 1);

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    int maks = 0, res = 0;

    while (not q.empty()) {
        auto [w, p] = q.front();
        q.pop();
        for (int ss : wec[w]) {
            if (ss == p)
                continue;
            q.push({ss, w});
            dist1[ss] = dist1[w] + 1;
            if (dist1[ss] > dist1[maks])
                maks = ss;
        }
    }

    q.push({maks, 0});
    while (not q.empty()) {
        auto [w, p] = q.front();
        q.pop();
        for (int ss : wec[w]) {
            if (ss == p)
                continue;
            q.push({ss, w});
            dist2[ss] = dist2[w] + 1;
        }
    }

    droptop(i, 1, n + 1)
    {
        res = max(res, (dist2[i] * k) - (dist1[i] * c));
    }
    return res;
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
