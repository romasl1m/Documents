/*
Now playing:
PFG - Mighty Mouse [NEVER SAY DIE]
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

int tab[201], quan[201];
int dp[20'001][202];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 0, n)
        {
            cin >> tab[i];
        }
        droptop(i, 0, n)
        {
            cin >> quan[i];
        }
        int k;
        cin >> k;

        droptop(i, 1, 20'001)
        {
            dp[i][201] = 1e9;
        }
        dp[0][201] = 0;
        droptop(i, 0, k)
        {
            droptop(j, 0, n)
            {
                if (dp[i][j] >= quan[j])
                    continue;
                if (i + tab[j] > k)
                    continue;
                if (dp[i + tab[j]][201] > dp[i][201] + 1) {
                    dp[i + tab[j]][201] = dp[i][201] + 1;
                    droptop(k, 0, n)
                    {
                        dp[i + tab[j]][k] = dp[i][k];
                    }
                    dp[i + tab[j]][j]++;
                }
            }
        }
        cout << dp[k][201] << "\n";
        droptop(i, 0, n)
        {
            cout << dp[k][i] << " ";
        }
    }
}
