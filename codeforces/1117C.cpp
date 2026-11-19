/*
Now playing:
Pink Floyd - Time [The Dark Side of the Moon]
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
#define int ll

ll pref[100'001][2];

pair<int, int> dir(char &c) {
    if (c == 'U')
        return {1, 1};
    if (c == 'D')
        return {1, -1};
    if (c == 'L')
        return {0, -1};
    return {0, 1};
}

int f() {
    ll a, b, x, y, n;
    string s;
    cin >> a >> b >> x >> y >> n >> s;
    pref[0][0] = 0, pref[0][1] = 0;
    droptop(i, 0, n)
    {
        pref[i + 1][0] = pref[i][0], pref[i + 1][1] = pref[i][1];
        auto cur = dir(s[i]);
        pref[i + 1][cur.first] += cur.second;
    }

    ll l = 0, r = 1e18, res = -1;
    while (l < r - 1) {
        ll mid = l + ((r - l) >> 1);
        ll div = mid / n; //, mod = max(0LL, (mid % n) - 1);
        ll mod = mid % n;
        ll curx = pref[n][0] * div + pref[mod][0],
           cury = pref[n][1] * div + pref[mod][1];

        if (abs(curx + a - x) + abs(cury + b - y) <= mid)
            r = mid, res = mid;
        else
            l = mid;
    }

    if (r >= 1e18)
        return -1;
    return r;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
