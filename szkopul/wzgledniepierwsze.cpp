/*
Now playing:

*/
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

int nwd(int a, int b) {
    while (b) {
        ll c = a % b;
        a = b, b = c;
    }
    return a;
}

int f() {
    ll n, k, c, cur = 0;
    cin >> n >> k >> c;
    vector<ll> wec;
    droptop(i, 1, n)
    {
        if (nwd(n, i) == 1)
            wec.pb(i);
    }
    droptop(i, k, k + c)
    {
        ll idx = i - 1, okr = idx / (ll)wec.size(), mod = idx % (ll)wec.size();
        cout << okr * n + wec[mod] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
