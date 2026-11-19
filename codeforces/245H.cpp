/*
Now playing:
Otsochodzi - NIC NIE MIJA [RIOTT]
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

bool palindrom[5'001][5'001];
int dp[5'001][5'001];

int f() {
    string s;
    cin >> s;
    droptop(i, 0, s.length())
    {
        palindrom[i][i] = dp[i][i] = true;
    }
    droptop(i, 0, s.length() - 1)
    {
        palindrom[i][i + 1] = (s[i] == s[i + 1]);
    }

    droptop(i, 3, s.length())
    {
        droptop(l, 0, s.length() - i + 1)
        {
            int r = l + i - 1;
            palindrom[l][r] = (s[l] == s[r]) and palindrom[l + 1][r - 1];
        }
    }

    droptop(i, 2, s.length() + 1)
    {
        droptop(l, 0, s.length() - i + 1)
        {
            int r = l + i - 1;
            dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1] + palindrom[l][r];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << "\n";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
