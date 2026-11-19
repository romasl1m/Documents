#include <iostream>
using namespace std;
int dp[11][101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,c;
    cin >> n >> q >> c;
    for(int i = 0; i < n; i++){
        int a,b,c1;
        cin >> a >> b >> c1;
        dp[c1][a][b]++;
    }
    for(int i = 0; i <= c; i++){
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                dp[i][j][k] += dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i][j - 1][k - 1];
            }
        }
    }
    while(q--){
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for(int i = 0; i <= c; i++){
            int cur = dp[i][x2][y2] - dp[i][x1 - 1][y2] - dp[i][x2][y1 - 1] + dp[i][x1 - 1][y1 - 1];
            cur *= (i + t) % (c + 1);
            res += cur;
        }
        cout << res << "\n";
    }
}
