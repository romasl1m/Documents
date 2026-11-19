/*
Now playing:
Young Multi - AK47 [AK47]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

string tab;
int dp[500'001];

void f() {
    int n;
    cin >> n >> tab;

    ll res = 0;

    int mid = 0, r = 0;
    droptop(i, 0, n - 1)
    {
        if (i < r) {
            int mir = (mid << 1) - i;
            dp[i] = min(dp[mir], r - i);
        }

        while (i - dp[i] >= 0 and i + dp[i] + 1 < n and tab[i - dp[i]] != tab[i + dp[i] + 1])
            dp[i]++;

        if (i + dp[i] > r)
            mid = i, r = i + dp[i];
        res += dp[i];
    }
    cout << res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
