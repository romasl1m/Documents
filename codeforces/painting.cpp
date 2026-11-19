#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[200'001];
long long int dp[200'001];
int sub[200'001];
long long int res = 0;
void change(int w, int ss){
    dp[w] -= dp[ss];
    dp[w] -= sub[ss];
    sub[w] -= sub[ss];
    sub[ss] += sub[w];
    dp[ss] += dp[w];
    dp[ss] += sub[w];
}
void undo(int w, int ss){
    dp[ss] -= dp[w];
    dp[ss] -= sub[w];
    sub[ss] -= sub[w];
    sub[w] += sub[ss];
    dp[w] += dp[ss];
    dp[w] += sub[ss];
}
void dfs(int w, int p){
    res = max(res,dp[w]);
    for(int ss : wec[w]){
        if(ss == p) continue;
        change(w,ss);
        dfs(ss,w);
        undo(w,ss);

    }
}
int f(int w, int p){
    int res = 1;
    for(int ss : wec[w]){
        if(ss == p) continue;
        res += f(ss,w);
    }
    sub[w] = res;
    return res;
}
long long dpc(int w, int p){
    dp[w] = sub[w];
    for(int ss : wec[w]){
        if(ss == p) continue;
        dp[w] += dpc(ss,w);
    }
    return dp[w];
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        wec[b].push_back(a);
    }
    f(1,0);
    dpc(1,0);
    dfs(1,0);
    cout << res;
    return 0;
}
