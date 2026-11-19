/*
Now playing:
Juice WRLD - Ring Ring (with Rvssian feat. Clever) [Death Race For Love (Bonus Track Version)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
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

const ll mod = 1e9 + 7;

ll pot(ll x, ll k) {
    if (k == 0)
        return 1;
    ll cur = pot(x, k >> 1);
    cur = cur * cur % mod;
    return (k & 1) ? cur * (x % mod) % mod : cur;
}

int f() {
    int n;
    cin >> n;
    vector<int> tab(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    sort(hotbox(tab), comp);

    int fst = n;
    droptop(i, 0, n - 1)
    {
        if (tab[i] == tab[i + 1]) {
            fst = i;
            break;
        }
    }

    ll res = 1;
    droptop(i, 1, fst + 1)
    {
        res = (res + pot(tab[i - 1] - 1, i)) % mod;
    }
    cout << res;
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
