/*
Now playing:
Playboi Carti - Right Now (feat. Pi'erre Bourne) [Die Lit]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (ll c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long
const ll mod = 998244353;

ll checkf(ll x) {
    if (x <= 0)
        return -x;
    int m = 64 - __builtin_clzll(x);
    if (x == (1LL << m) - 1)
        return m;
    ll res = m + (1LL << m) - 1 - x;
    if (m < 3)
        return res;
    return min(res, m + checkf(x - (1LL << (m - 1)) + 2));
}

int f() {
    ll l, r;
    cin >> l >> r;
    ll sum = 0;
    droptop(i, l, r + 1)
    {
        sum = (sum + checkf(i)) % mod;
    }
    cout << sum;
    return 0;
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
