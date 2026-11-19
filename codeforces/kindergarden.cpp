/*
Now playing:
Denzel Curry - Nobody Speak Part 2 [Nobody Speak Part 2]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll
int tab[1'000'003];
int dp[1'000'003];
signed main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        int l = 1;
        droptop(1, n + 1)
        {
            cin >> tab[i];
        }
        droptop(2, n + 1)
        {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], dp[i - 2] + abs(tab[i] - tab[i - 1]));
            dp[i] = max(dp[i], dp[l] + abs(tab[i] - tab[l + 1]));
            dp[i] = max(dp[i], dp[l - 1] + abs(tab[i] - tab[l]));
            if (tab[i] < tab[i - 1] and tab[i + 1] >= tab[i])
                l = i;
            if (tab[i] > tab[i - 1] and tab[i + 1] <= tab[i])
                l = i;
        }
        cout << dp[n];
    }
    return 0;
}
