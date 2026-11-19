/*
Now playing:
Linkin Park - Faint [Meteora]
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

ll cntf(const string &s, const int &n) {
    int l = 0, r = 0;
    ll res = 1;
    droptop(i, 0, n)
    {
        if (s[i] == '1')
            r++, res += r;
        else
            l++, res += l;
    }
    return res;
}

ll build10(int &popcnt, const int &n) {
    string cur(n, '0');
    droptop(i, 0, popcnt)
    {
        cur[i] = '1';
    }
    return cntf(cur, n);
}

int f() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int popcnt = count(hotbox(s), '1');

    int l = max(0, popcnt - k), r = r = min(n, popcnt + k);
    cout << max(build10(l, n), build10(r, n));

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
