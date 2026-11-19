#include <iostream>
#include <vector>
using namespace std;
const long long mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<int> par(n + 1);
        vector<int> dep(n + 1);
        vector<vector<int>> wec(n + 1);
        dep[1] = 0;
        wec[0].push_back(1);
        for(int i = 2; i <= n; i++){
            cin >> par[i];
            dep[i] = dep[par[i]] + 1;
            wec[dep[i]].push_back(i);
        }
        vector<long long> dp(n + 1, 0);
        vector<long long> dsum(n + 1, 0);
        dp[1] = 1;
        dsum[0] = 1;
        long long res = 1;
        for(int i = 1; i <= n; i++){
            if(wec[i].empty()) break;
            for(int ss : wec[i]){
                if(i == 1) dp[ss] = dsum[0];
                else dp[ss] = (dsum[i - 1] - dp[par[ss]] + mod) % mod;
                dsum[i] = (dsum[i] + dp[ss]) % mod;
                res = (res + dp[ss]) % mod;
            }
        }

        cout << res << "\n";
    }
    return 0;
}
