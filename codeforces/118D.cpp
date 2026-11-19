/*
Now playing:
Juice WRLD - Big [Death Race For Love (Bonus Track Version)]
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
#define int ll

int dp[101][101][2];

int f() {
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;

    dp[0][0][0] = dp[0][0][1] = 1;
    droptop(i, 0, n + 1)
    {
        droptop(j, 0, m + 1)
        {

            droptop(k, 1, min(k2, m - j) + 1)
            {
                dp[i][j + k][1] += dp[i][j][0];
            }
            droptop(k, 1, min(k1, n - i) + 1)
            {
                dp[i + k][j][0] += dp[i][j][1];
            }
        }
    }

    return dp[n][m][0] + dp[n][m][1];
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            cout << f();
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
