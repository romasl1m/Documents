/*
Now playing:
Offset - R4W (feat. Quavo) [GMFU]
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

const ll mod = 1e9 + 7, mod2 = 1e9 + 9, base = 33, base2 = 31;
ll basep[200'001], basep2[200'001];

int f() {
    int n, l, r, maks, res = 0;
    string s;
    cin >> n >> maks >> maks >> s;

    vector<ll> hasz(n + 1), hasz2(n + 1);
    droptop(i, 0, n)
    {
        hasz[i + 1] = (mod + hasz[i] + (s[i] - 'a' + 1) * basep[i]) % mod;
        hasz2[i + 1] = (mod2 + hasz2[i] + (s[i] - 'a' + 1) * basep2[i]) % mod2;
    }

    auto checkf = [&](int len) {
        if (not len)
            return true;
        int cnt = 0;
        ll needed = hasz[len], needed2 = hasz2[len];

        for (int i = 0; i + len <= n;) {
            ll cur = (hasz[i + len] - hasz[i] + mod) % mod,
               cur2 = (hasz2[i + len] - hasz2[i] + mod2) % mod2;
            if (cur == (needed * basep[i]) % mod and cur2 == (needed2 * basep2[i]) % mod2)
                cnt++, i += len;
            else
                i++;
        }
        return cnt >= maks;
    };

    l = 0, r = (n / maks);
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (checkf(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    basep[0] = basep2[0] = 1;
    droptop(i, 1, 200'001)
    {
        basep[i] = (basep[i - 1] * base) % mod;
        basep2[i] = (basep2[i - 1] * base2) % mod2;
    }
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
