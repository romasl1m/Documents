#include <iostream>
#include <algorithm>
using namespace std;
unsigned int tab[1001][1001];
unsigned int dp[1001][1001];
unsigned int last[1001][1001];
unsigned int inp[1001][1001];
unsigned int wyn[1001];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x;
            cin >> x;
            inp[i][j] = x;
        }
    }
    for(int j = 1; j <= n; j++){
        for(int i = j - 1; i >= 0; i--){
            tab[i][j] = inp[i][j] + tab[i][j - 1] + tab[i + 1][j] - tab[i + 1][j - 1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int j = 1; j <= k; j++){
        for(int i = 0; i < n - 1; i++){
            if(j == 1){
                dp[i][j] = tab[0][i];
            }else{
                dp[i][j] = 2'000'000'001;
                for(int h = 0; h < i; h++){
                    // dp[i][j] = max(dp[i][j], dp[h + 1][j - 1] + sumf(h + 1, n, i, h + 1));
                    if(dp[h][j - 1] + tab[h + 1][i] < dp[i][j]){
                        dp[i][j] = dp[h][j - 1] + tab[h + 1][i];
                        last[i][j] = h;
                    }
                }
            }
        }
    }
    // cout << endl << endl;
    // for(int i = 0; i <= n; i++){
    //     cout << dp[i][k] << " ";
    // }
    // cout << endl;
    unsigned int res = 2'000'000'001;
    unsigned int ost = -1;
    for(int i = 0; i < n - 1; i++){
        if(dp[i][k] + tab[i + 1][n - 1] < res){
            res = dp[i][k] + tab[i + 1][n - 1]; 
            ost = i;
        }
    }
    for(int i = k - 1; i >= 0; i--){
        wyn[i] = ost;
        ost = last[ost][i + 1];
    }
    sort(wyn, wyn + k);
    for(int i = 0; i < k - 1; i++){
        cout << wyn[i] + 1 << " ";
    }
    cout << wyn[k - 1] + 1;
    // cout << res;
    return 0;
}
