/*
Now playing:
Otsochodzi - RIOTT [RIOTT]
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
#define int ll
ll a[1'000'001], dp[1'000'001];

inline ll costf(const int &j, const int &i) {
    if (j < 1 || j > i)
        return 2e18;
    ll gf = dp[j - 1] - 2LL * j,
       ff = (a[i] - i) - (ll)j;
    return max(gf, ff);
}

int f() {
    int n, s;
    cin >> n >> s;
    ll cur = -2e18;
    droptop(i, 1, n + 1)
    {
        cin >> a[i];
        if (a[i] <= cur)
            a[i] = cur + 1;
        cur = a[i];
    }

    droptop(i, 1, n + 1)
    {
        int l = 1, r = i, res = i;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (dp[mid - 1] - mid >= a[i] - (ll)i)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        ll ffgfmin = min(costf(res, i), costf(res - 1, i));
        dp[i] = (s << 1) + (i << 1) + ffgfmin;
    }
    return dp[n];
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f();
        cout << "\n";
    }
    return 0;
}
