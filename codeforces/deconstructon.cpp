#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long mod = 998244353;
void dfs(int w, int p, vector<int> &dp, const vector<vector<int>> &wec){
    dp[w] = 0;
    for(int ss : wec[w]){
        if(ss == p) continue;
        dfs(ss,w,dp,wec);
        dp[w] = max(dp[w], dp[ss]);
        dp[w] = max(dp[w], ss);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> wec(n + 1);
        vector<int> dp(n + 1);
        for(int i = 1; i < n; i++){
            int a,b;
            cin >> a >> b;
            wec[a].push_back(b);
            wec[b].push_back(a);
        }
        if(n == 2){
            cout << 1 << "\n";
            continue;
        }
        int maks = 0;
        for(int i = 1; i <= n; i++){
            if(wec[i].size() == 1){
                maks = max(maks, i);
            }
        }
        dfs(n,-1,dp,wec);
        int res = 0, high = 0, high1 = 0;
        for(int i : wec[n]){
            int cur = max(i,dp[i]);
            if(cur > high){
                high1 = high;
                high = cur;
            }else if(cur > high1){
                high1 = cur;
            }
        }
        res = high1;
        vector<long long> tab(n + 1, 0);
        vector<long long> pref(n + 1, 0);
        tab[maks] = pref[maks] = 1;
        for(int i = maks + 1; i <= n; i++){
            int lim = (i == n ? res : dp[i]);
            if(lim + 1 <= i - 1){
                tab[i] = (pref[i - 1] - pref[lim] + mod) % mod;
            }else{
                tab[i] = 0;
            }
            pref[i] = (pref[i - 1] + tab[i]) % mod;
        }
        cout << tab[n] << "\n";
    }
}