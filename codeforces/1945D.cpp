/*
Now playing:

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

ll f() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    droptop(i, 0, n)
    {
        cin >> a[i];
    }
    droptop(i, 0, n)
    {
        cin >> b[i];
    }

    ll cur = 0, total = 0;
    cookie(i, n - 1, m)
    {
        if (a[i] < b[i])
            total += a[i] + cur, cur = 0;
        else
            cur += b[i];
    }

    ll res = 1e18;
    cookie(i, m - 1, 0)
    {
        res = min(res, total + a[i] + cur), cur += b[i];
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
