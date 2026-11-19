/*
Now playing:
Nirvana - In Bloom [Nevermind (Remastered)]
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

int f() {
    int n;
    cin >> n;
    vector<ll> pref(n + 1);
    vector<ll> tab(n + 1);
    droptop(i, 1, n + 1)
    {
        ll x;
        cin >> x;
        pref[i] = pref[i - 1] + x, tab[i] = x;
    }

    vector<int> wec;
    int idx = 0;
    while (idx < n) {
        wec.pb(idx);
        while (idx < n and tab[idx + 1] >= 0)
            wec.pop_back(), wec.pb(++idx);
    }
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
