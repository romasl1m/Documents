/*
Now playing:
Bring Me The Horizon - Avalanche [That's The Spirit]
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

const int mks = 1e9;
struct st {
    int tab[7]{
        mks,
        mks,
        mks,
        mks,
        mks,
        mks,
        mks};
};

int idx(char c) {
    if (c == '0')
        return 0;
    if (c == '-')
        return 1;
    return 2;
}

const pair<int, int> range[3] = {{3, 3}, {0, 2}, {4, 6}};
void f() {
    int n;
    string s;
    cin >> n >> s;

    int maks = 0, cur = 0;
    vector<st> dp(n + 1);
    dp[0].tab[3] = 0;

    droptop(i, 0, n)
    {
        droptop(j, 0, 7)
        {
            if (dp[i].tab[j] == 1e9)
                continue;

            const auto &[l, r] = range[idx(s[i])];
            droptop(nxt, l, r + 1)
            {
                if (nxt == j)
                    continue;
                dp[i + 1].tab[nxt] = min(dp[i + 1].tab[nxt], max(dp[i].tab[j], abs(nxt - j)));
            }
        }
    }
    int res = 1e9;
    droptop(i, 0, 7)
    {
        res = min(res, dp[n].tab[i]);
    }
    cout << (res == 1e9 ? -1 : res) << "\n";
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
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
