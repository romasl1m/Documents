/*
Now playing:
Juice WRLD - Demo Wreck [Demo Wreck]
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
#define cookie(c, n, a) for (int c = (n); c >(a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[100'001];

int dfs(int w, int p, int &res, const int &mid) {
    int cur = 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        cur += dfs(ss, w, res, mid);
    }

    if (p > 0 and mid <= cur)
        res++, cur = 0;
    return cur;
}
bool ok(int mid, const int &k) {
    int res = 0,
        cur = dfs(1, 0, res, mid);
    return ((res == k and cur >= mid) or res > k);
}

int f() {
    int n, k;
    cin >> n >> k;
    droptop(i, 1, n + 1)
    {
        wec[i].clear();
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    int l = 1, r = (n / (k + 1)) + 1;
    while (l < r - 1) {
        int mid = l + ((r - l) >> 1);
        // cerr << "mid " << mid << endl;
        ;
        if (ok(mid, k))
            l = mid;
        else
            r = mid;
    }
    return l;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
