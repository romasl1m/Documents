/*
Now playing:
Juice WRLD - Barbarian [The Party Never Ends 2.0]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

bool tab[1'000'001];
bool tam[1'000'001];
const int mn = 31, mod = 1e9 + 7;

int potmod(ll base, ll wyk) {
    ll res = 1;
    base %= mod;
    while (wyk > 0) {
        if (wyk % 2 == 1)
            res = (res * base) % mod;
        wyk >>= 1;
        // res >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, a, b, p, m;
        cin >> n >> a >> b >> p >> m;
        droptop(i, 0, m)
        {
            char x;
            cin >> x;
            tam[i] = (x == '1');
        }
        droptop(i, 0, n)
        {
            tab[i] = ((a * i + b) % n) >= p;
        }

        int res = 0;
        int hashn = 0, hashm = 0;
        // ll wspodejm = 0;
        ll wspodejm = potmod(mn, m - 1);
        droptop(i, 0, m)
        {
            hashn = (mn * hashn + tab[i]) % mod,
            hashm = (mn * hashm + tam[i]) % mod;
        }

        droptop(i, 0, n - m + 1)
        {
            if (hashn == hashm) {
                res++;
            }
            if (i < n - m) {
                int old = tab[i];
                hashn = (hashn - (old * wspodejm) % mod) % mod;
                if (hashn < 0)
                    hashn += mod;
                hashn = (hashn * mn + tab[i + m]) % mod;
            }
        }
        cout << res;
    }
}
