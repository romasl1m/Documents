/*
Now playing:
Landon Cube - ADMIT [WHAT WOULD GOD SAY?]
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

ll int tab[100'001];
ll int dp[100'001];

ll int f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        tab[x]++;
    }

    droptop(i, 1, 100'001)
    {
        dp[i] = max(dp[i - 1], dp[max(0, i - 2)] + (tab[i] * i));
    }
    return dp[100'000];
    return 0;
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
