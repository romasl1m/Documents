/*
Now playing:
Lil Peep - hellboy [HELLBOY]
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

ll a[21], b[21];
pair<ll, ll> dp[21][(1 << 20)];

void f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> a[i];
    }
    droptop(i, 1, n + 1)
    {
        cin >> b[i];
    }

    droptop(i, 0, (1 << n))
    {
        dp[0][i] = {-1e18, 0};
    }

    int m;
    cin >> m;
    droptop(i, 0, m)
    {
        string s;
        ll cost;
        cin >> s >> cost;
        int cur = 0;
        droptop(j, 0, s.length())
        {
            if (s[j] - '0')
                cur |= (1 << j);
        }

        if (dp[0][cur].first == -cost)
            dp[0][cur].second++;
        else if (dp[0][cur].first < -cost)
            dp[0][cur] = {-cost, 1};
    }
    droptop(i, 1, n + 1)
    {
        int bit = i - 1;
        droptop(j, 0, (1 << n))
        {
            int alt = j ^ (1 << bit);
            pair<ll, ll> op1 = {-1e18, 0};
            if (dp[i - 1][j].first != -1e18) {
                int gain = (j & (1 << bit)) ? b[i] : a[i];
                op1 = {dp[i - 1][j].first + ((j & (1 << bit)) ? b[i] : a[i]), dp[i - 1][j].second};
            }

            pair<ll, ll> op2 = {-1e18, 0};
            if (dp[i - 1][alt].first != -1e18) {
                op2 = dp[i - 1][alt];
            }

            if (op1.first > op2.first)
                dp[i][j] = op1;
            else if (op2.first > op1.first)
                dp[i][j] = op2;
            else
                dp[i][j] = {op1.first, op1.second + op2.second};
        }
    }

    // droptop(i, 1, n + 1)
    // {
    //     int bit = i - 1;
    //     droptop(j, 0, (1 << n))
    //     {
    //         if (dp[i - 1][j].first == -1e9)
    //             dp[i][j] = {-1e9, 0};
    //         else
    //             dp[i][j] = pair<int, int>{dp[i - 1][j].first + (j & (1 << bit) ? b[i] : a[i]), dp[i - 1][j].second};
    //     }
    //
    //     droptop(j, 0, (1 << n))
    //     {
    //         if (dp[i][j].first == dp[i][j ^ (1 << bit)].first)
    //             dp[i][j].second += dp[i][j ^ (1 << bit)].second;
    //         else if (dp[i][j].first < dp[i][j ^ (1 << bit)].first)
    //             dp[i][j] = dp[i][j ^ (1 << bit)];
    //     }
    // }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int cur = 0;
        droptop(j, 0, s.length())
        {
            if (s[j] - '0')
                cur |= (1 << j);
        }

        cout << dp[n][cur].first << " " << dp[n][cur].second << "\n";
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
