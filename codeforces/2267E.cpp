/*
Now playing:
Gunna - DOLLAZ ON MY HEAD (feat. Young Thug) [WUNNA]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int f() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> b(n + 1, false);

    int tab[] = {0, 0};
    droptop(i, 0, n)
    {
        tab[s[i] - '0']++;
    }

    ll res = 0;
    droptop(i, 0, n - 1)
    {
        b[i] = (s[i] != s[i + 1]),
        res += (b[i] ? (ll)(i + 1) * (ll)(n - 1 - i) : 0LL);
    }

    cout << ((res + (ll)tab[false] * (ll)tab[true]) >> 1) << " ";

    while (q--) {
        int cur;
        cin >> cur;
        cur--;

        if (cur > 0)
            res += ((ll)(cur) * (ll)(n - cur)) * (ll)(b[cur - 1] ? -1LL : 1LL), b[cur - 1] ^= 1;
        if (cur < n - 1)
            res += ((ll)(cur + 1) * (ll)(n - cur - 1)) * (ll)(b[cur] ? -1LL : 1LL), b[cur] ^= 1;
        tab[s[cur] - '0']--, s[cur] = (s[cur] == '0' ? '1' : '0'), tab[s[cur] - '0']++;

        cout << ((res + (ll)tab[false] * (ll)tab[true]) >> 1) << " ";
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
