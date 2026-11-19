/*
Now playing:
Lil Uzi Vert - Erase Your Social [The Perfect LUV Tape]
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

int tab[200'001];
const ll mod = 998244353;
ll pot(ll a, ll b) {
    ll cur = pot(a, (b >> 1));
    return ((b & 1 ? a : 1) * cur * cur) % mod;
}
int f() {
    int n;
    cin >> n;
    tab[0] = 0, tab[1] = 1;
    droptop(i, 2, n)
    {
        tab[i] = (tab[i - 1] + tab[i - 2] + mod) % mod;
    }
    return ((ll)tab[n] * pot(2, n)) % mod;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
