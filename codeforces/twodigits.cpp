/*
Now playing:
Migos - White Sand [Culture II]
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
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        vector<int> pref(n + 1), pref1(m + 1);
        droptop(i, 0, n)
        {
            pref[i + 1] = (pref[i] + (a[i] - '0')) % 10;
        }
        droptop(i, 0, m)
        {
            pref1[i + 1] = (pref1[i] + (b[i] - '0')) % 10;
        }
        n++, m++;
        if (pref1.back() != pref.back()) {
            cout << -1 << "\n";
            continue;
        }
        vector<vector<int>> dp(n + 2, vector<int>(m + 2));
        droptop(i, 0, n + 1)
        {
            droptop(j, 0, m + 1)
            {
                if (i < n)
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j < m)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
                if (i < n and j < m and pref[i] == pref1[j])
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
        cout << dp[n][m] - 1 << "\n";
    }
}
