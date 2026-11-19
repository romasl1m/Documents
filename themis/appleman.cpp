#include <iostream>
#include <vector>
using namespace std;
int color[100'001];
vector<int> wec[100'001];
long long dp[100'001][2];
const long long mod = 1e9 + 7;
int dfs(int w){
    if(color[w] == 1){
        dp[w][1] = 1;
    }else{
        dp[w][0] = 1;
    }
    for(int ss : wec[w]){
        // if(ss == p) continue;
        dfs(ss);
        dp[w][1] = ((dp[w][1] * dp[ss][1]) % mod + (dp[w][0] * dp[ss][1]) % mod + (dp[w][1] * dp[ss][0]) % mod) % mod;
        dp[w][0] = ((dp[w][0] * dp[ss][0]) % mod + (dp[w][0] * dp[ss][1]) % mod) % mod;
    }
    return dp[w][1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        wec[x].push_back(i);
        // wec[i].push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> color[i];
    }
    cout << dfs(0);
    return 0;
}
