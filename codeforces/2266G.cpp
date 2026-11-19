/*
Now playing:
Otsochodzi - HALO? [RIOTT]
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
#define int ll

ll nwd(ll a, ll b) {
    if (b > a)
        swap(a, b);
    while (b) {
        ll c = b;
        b = a % b, a = c;
    }
    return a;
}

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &dp, const vector<int> &a, const vector<int> &b, vector<int> &gcdtab) {
    ll sum = 0, cur = b[w], maks;
    if (wec[w].size() == 1 and w != 1) {
        gcdtab[w] = b[w];
    } else {
        for (int ss : wec[w]) {
            if (ss == p)
                continue;
            dfs(ss, w, wec, dp, a, b, gcdtab);
            sum += a[ss];
            if (gcdtab[ss] != b[ss])
                cur = nwd(cur, gcdtab[ss]);
        }

        cur = nwd(cur, sum % b[w]);
        gcdtab[w] = cur;
    }
    maks = (b[w] - 1) - ((b[w] - 1 - (a[w] % b[w])) % gcdtab[w]);
    dp[w] = max(maks, a[w]);
}

int f() {
    int n;
    cin >> n;
    vector<ll> tab(n + 1), mod(n + 1);
    vector<vector<int>> wec(n + 1);

    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    droptop(i, 1, n + 1)
    {
        cin >> mod[i];
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    vector<int> dp(n + 1), gcdtab(n + 1);
    dfs(1, 0, wec, dp, tab, mod, gcdtab);

    ll res = 0;
    droptop(i, 1, n + 1)
    {
        res += dp[i];
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
