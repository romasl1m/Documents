/*
Now playing:
Linkin Park - Up From the Bottom [From Zero (Deluxe Edition)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (long long i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
ll tab[5'001];
ll dp[5'001];
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n + 1)
        {
            dp[i] = 1e9;
            tab[i] = 0;
        }
        droptop(1, n + 1)
        {
            int x;
            cin >> x;
            if (x < n)
                tab[x]++;
        }

        int m = 0;
        while (tab[m])
            m++;
        dp[m] = 0;
        for (ll i = m; i >= 1; i--) {
            for (ll j = 0; j < i; j++) {
                dp[j] = min(dp[j], dp[i] + i * tab[j]);
            }
        }
        cout << dp[0] - m << "\n";
    }
}
