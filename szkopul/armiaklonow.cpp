/*
Now playing:
Young Stoner Life - Eaters [Slime Language 3]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll dp[1'000'001];
void f() {
    ll a, b, n;
    cin >> n >> a >> b;
    droptop(i, 2, (n << 1) | 1)
    {
        dp[i] = 1e18;
    }

    droptop(i, 1, n + 1)
    {
        for (int j = 2; (j - 1) * i <= n; j++) {
            dp[j * i] = min(dp[i * j], dp[i] + a + (j - 1) * b);
            // cout << j * i << endl;
            // cerr << i << " " << j << endl;
        }
    }

    ll res = 1e18;
    droptop(i, n + 1, (n << 1) | 1)
    {
        res = min(res, dp[i]);
    }
    cout << res;
}

int main() {
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
