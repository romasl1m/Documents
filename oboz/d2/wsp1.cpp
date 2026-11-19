#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[5'003];
int dp[5003][5003];
void dfs(int i, int j){
  if(i >= j){
    for(int ss : wec[i]){
      if(ss == j or ss >= i) continue;
      dp[i][j] = max(dp[i][j], 1 + dp[j][ss]);
    } 
  }else{
    for(int ss : wec[j]){
      if(ss == i or ss >= j) continue;
      dp[i][j] = max(dp[i][j], 1 + dp[i][ss]);
    }
  } 
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b1;
    cin >> a >> b1;
    a++; b1++;
    wec[a].push_back(b1);
    wec[b1].push_back(a);
  } 
  for(int i = 2; i <= n + 1; i++){
    wec[0].push_back(i);
    wec[1].push_back(i);
    wec[i].push_back(0);
    wec[i].push_back(1);
  }
  wec[0].push_back(1);
  wec[1].push_back(0);
  for(int i = 0; i <= n + 1; i++){
    for(int j = 0; j <= n + 1; j++){
        dfs(i,j);
    }
  }
  int res = 0;
  for(int i = 0; i <= n + 1; i++){
    res = max(dp[i][i], res);
  } 
  cout << res - 1;
  return 0;
}
