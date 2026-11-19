/*
Now playing:
JACKBOYS - GATTI [JACKBOYS]
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

// int tab[10'001];
const int base = 24;
ll sos[1 << base];

ll int f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        string s;
        cin >> s;
        int mask = 0;
        for (char &c : s) {
            mask |= (1 << (c - 'a'));
        }
        sos[mask]++;
    }

    droptop(i, 0, base)
    {
        droptop(mask, 0, (1 << base))
        {
            if (mask & (1 << i))
                sos[mask] += sos[mask ^ (1 << i)];
        }
    }

    ll res = 0;
    droptop(i, 0, (1 << base))
    {
        ll cur = n - sos[((1 << base) - 1) ^ i];
        res ^= cur * cur;
        // res ^= n - (sos[((1 << base) - 1) ^ i]);
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
