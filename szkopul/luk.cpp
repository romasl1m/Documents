#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[300'001];
int dp[300'001];
bool wiz[300'001];
int res = 0;
void dfs(int w, int agents){
  wiz[w] = true;
  dp[w] = 0;
  for(int ss : wec[w]){
    if(wiz[ss]) continue;
    dfs(ss, agents);
    dp[w] += dp[ss] + 1;
  }
  dp[w] = max(0, dp[w] - agents);
  wiz[w] = false;
}
int bins(int n){
  int l = 0, r = n - 1;
  while(l < r){
    int mid = (l + r) >> 1;
    dfs(1, mid);
    if(dp[1] == 0){
      r = mid;
    }else{
      l = mid + 1;
    }
  }
  return l;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >>  n;
  for(int i = 1; i < n; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
  }
  cout << bins(n);
  return 0;
}
