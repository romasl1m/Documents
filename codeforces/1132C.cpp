/*
Now playing:
Artemas - i always kinda knew you’d be the death of me [yustyna]
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

void f() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<ll> tab(n);
    droptop(i, 0, n)
    {
        cin >> tab[i], sum += tab[i];
    }

    sort(hotbox(tab));
    int c = count(hotbox(tab), tab.back());
    if (k < c or k > n) {
        cout << "no";
        return;
    }

    cout << "yes\n";
    droptop(i, n - k, n)
    {
        cout << tab[i] << " ";
    }
    cookie(i, n - k - 1, 0)
    {
        cout << tab[i] << " ";
    }
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
