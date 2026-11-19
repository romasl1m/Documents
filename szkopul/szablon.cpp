/*
Now playing:
Linkin Park - No More Sorrow [Minutes to Midnight (Deluxe Edition)]
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

int pi[500'001];
int dp[500'001];
int last[500'001];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        droptop(i, 1, n)
        {
            int j = pi[i - 1];
            while (j > 0 and s[j] != s[i]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }

        dp[0] = 1;
        last[1] = 0;
        droptop(i, 1, n)
        {
            dp[i] = i + 1;
            int pot = dp[pi[i] - 1];
            if (pi[i] > 0 and last[pot] >= i - pi[i]) {
                dp[i] = pot;
            }
            last[dp[i]] = i;
        }
        // droptop(i, 0, n)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;

        cout << dp[n - 1];
        return 0;
    }
}
