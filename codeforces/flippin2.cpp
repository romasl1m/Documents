#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> tab(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> tab[i];
        }
        vector<vector<vector<long long>>> dp(n + 2, vector<vector<long long>>(2, vector<long long>(2, -1e18)));
        vector<vector<vector<int>>> opt(n + 2, vector<vector<int>>(2, vector<int>(2, 0)));
        vector<vector<vector<int>>> choise(n + 2, vector<vector<int>>(2, vector<int>(2, 0)));
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    dp[i][j][k] = -1e18;
                }
            }
        }
        dp[n + 1][0][0] = 0;
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    if(dp[i + 1][j][k] == -1e18) continue;
                    long long cur = dp[i + 1][j][k] + tab[i] * (j ? -1 : 1);
                    if(cur > dp[i][j][k]){
                        dp[i][j][k] = cur;
                        opt[i][j][k] = 0;
                        choise[i][j][k] = k;
                    }
                    if(k == 0 and tab[i] < 0) continue;
                    else{
                        int obr = j ^ 1;
                        int nk = 1;
                        long long cur1 = dp[i + 1][j][k] + tab[i] * (obr ? -1 : 1);
                        if(cur1 > dp[i][obr][nk]){
                            dp[i][obr][nk] = cur1;
                            opt[i][obr][nk] = 1;
                            choise[i][obr][nk] = k;
                        }
                    }
                }
            }
        }
        long long res = -1e18;
        int ro = 0, rk = 0;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(dp[1][j][k] > res){
                    res = dp[1][j][k];
                    ro = j;
                    rk = k;
                }
            }
        }
        vector<int> wec;
        for(int i = 1; i <= n; i++){
            if(opt[i][ro][rk] == 1){
                wec.push_back(i);
            }
            int nro = ro ^ opt[i][ro][rk];
            int nrk = choise[i][ro][rk];
            ro = nro;
            rk = nrk;
        }
        reverse(wec.begin(), wec.end());
        deque<int> dq;
        int f = -1;
        for(int i : wec){
            if(tab[i] > 0){
                if(f != -1) dq.push_front(f);
                f = i;
            }else{
                dq.push_back(i);
            }
        }
        vector<int> ans;
        if(f != -1) ans.push_back(f);
        for(int i : dq){
            ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(int i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }
}