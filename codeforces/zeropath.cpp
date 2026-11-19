#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int dp[1001][1001][2];
int tab[1001][1001];
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n,m;
        cin >> n >> m;
        droptop(0,n){
            for(int j = 0; j < m; j++){
                dp[i][j][0] = dp[i][j][1] = 0;
                cin >> tab[i][j];
            }
        }
        dp[0][0][0] = dp[0][0][1] = tab[0][0];
        droptop(1, n){
            dp[i][0][0] = dp[i][0][1] = dp[i - 1][0][1] + tab[i][0];
        }
        droptop(1, m){
            dp[0][i][0] = dp[0][i][1] = dp[0][i - 1][1] + tab[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + tab[i][j];
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + tab[i][j];
                // cout << dp[i][j][0] << dp[i][j][1] << " ";
            }
            // cout << endl;
        }
        if((n + m) % 2 == 0 or dp[n - 1][m - 1][0] > 0 or dp[n - 1][m - 1][1] < 0){
            cout << "no\n";
        }else{
            cout << "yes\n";
        }
    }
}

