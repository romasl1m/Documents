/*
Now playing:
Travis Scott - through the late night [Birds In The Trap Sing McKnight]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

ll sq(ll a) {
    return a * a;
}
signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pos(n + 1, 0), tab(n << 1 | 1);
        vector<int> dp(n << 1 | 1, 0);
        droptop(i, 1, (n << 1 | 1))
        {
            cin >> tab[i];
            dp[i] = dp[i - 1] + 1;
            if (pos[tab[i]] == 0) {
                pos[tab[i]] = i;
            } else {
                int minl = pos[tab[i]];
                // int j = i;
                // while (j >= minl) {
                //     minl = min(minl, pos[tab[j]]);
                //     j--;
                // }
                int len = i - minl + 1;
                dp[i] = max(dp[i], sq(len) + dp[minl - 1]);
            }
        }
        cout << dp[n << 1] << "\n";
    }
}
