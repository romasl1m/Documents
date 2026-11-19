/*
Now playing:
Linkin Park - One Step Closer [Hybrid Theory]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long
#define int ll

int f() {
    int n;
    cin >> n;
    vector<ll> tab(n);
    ll sum = 0;
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        tab[i] = (x), sum += tab[i];
    }
    sort(hotbox(tab), comp);

    ll gr1 = 0, gr2 = 0;
    for (const auto &x : tab) {
        ll cur = ((ll)1 << x);
        if (gr1 < gr2)
            gr1 += cur;
        else
            gr2 += cur;
    }

    return gr1 * gr2;
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
