/*
Now playing:

*/
#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

const ll mod = 1e9 + 7;
const int MAXN = 3'000'000;

ll sila[MAXN + 1];
ll silarew[MAXN + 1];

ll pot(ll base, ll k) {
    base %= mod;
    ll res = 1;
    while (k > 0) {
        if (k % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        k >>= 1;
    }
    return res;
}

ll odw(ll x) {
    return pot(x, mod - 2);
}

void prep(int n) {
    sila[0] = 1;
    droptop(i, 1, n + 1)
    {
        sila[i] = (sila[i - 1] * i) % mod;
    }
    silarew[n] = odw(sila[n]);
    for (int i = n - 1; i >= 0; i--) {
        silarew[i] = (silarew[i + 1] * (i + 1)) % mod;
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int a, b, c, x;
        cin >> a >> b >> c >> x;

        int n = a + b + c;
        prep(n);

        int limit = min(a, b);
        ll res = 0;

        ll inw = (silarew[c] * silarew[x]) % mod;

        droptop(i, x, limit + 1)
        {
            ll cur = sila[n - i];
            cur = (cur * silarew[a - i]) % mod;
            cur = (cur * silarew[b - i]) % mod;
            cur = (cur * silarew[i - x]) % mod;
            cur = (cur * inw) % mod;

            if ((i - x) % 2 == 0) {
                res = (res + cur) % mod;
            } else {
                res = (res - cur + mod) % mod;
            }
        }

        cout << res << "\n";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
