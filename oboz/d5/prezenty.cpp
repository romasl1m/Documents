#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[50'001];
int lca[50'001][17];
int dep[50'001];
int res[50'001];
void dfs(int w, int p){
  lca[w][0] = p;
  for(int i = 1; i < 17; i++){
    if(lca[w][i - 1] == -1){
      lca[w][i] = -1;
      continue;
    }
    lca[w][i] = lca[lca[w][i - 1]][i - 1];
  }
  for(int ss : wec[w]){
    if(ss == p) continue;
    dep[ss] = dep[w] + 1;
    dfs(ss,w);
  }
}
int pushin(int w, int p){

    // cout << "RES BEFORE " << res[w] << " AND ";
  for(int ss : wec[w]){
    if(ss == p) continue;
    res[w] += pushin(ss,w);
  }

    // cout << res[w] << " AFTER\n";
  return res[w];
}
int lift(int a, int d){
  for(int i = 0; i < 17; i++){
    if(d & (1 << i)){
      a = lca[a][i];
      if(a == -1) break;
    }
  }
  return a;
}
int lcaf(int a, int b){
  if(dep[a] > dep[b]){
    swap(a,b);
  }
  b = lift(b, dep[b] - dep[a]);
  // cout << a << " " << b << endl;
  if(a == b){
    return a; 
  }
  for(int i = 16; i >= 0; i--){
    if(lca[a][i] != lca[b][i] and lca[a][i] >= 1){
      a = lca[a][i];
      b = lca[b][i];
    }
  }
  return lca[a][0];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 1; i < n; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 17; j++){
      lca[i][j] = -1;
    }
  }
  dfs(1,-1);
  while(k--){
    int a,b;
    cin >> a >> b;
    // if(a == 1){
    //   res[b]++;
    //   continue;
    // }else if(b == 1){
    //   res[a]++;
    //   continue;
    // }
    res[b]++;  
    res[a]++;
    // cout << "RES5 " << res[5] << endl;
    int p = lcaf(a,b);
    // cout << "LCA " << a << " " << b  << " is " << p << endl;
    res[p]--;
    if(p > 1) res[lca[p][0]]--;
    // else{
    //   res[p]--;
    // }
  }
  // for(int i = 1; i <= n; i++){
  //   cout << res[i] << " ";
  // }
  // cout << endl;
  pushin(1,-1);
  int maks = 0;
  for(int i = 1; i <= n; i++){
    // cout << res[i] << " ";
    maks = max(maks, res[i]);
  }
  cout << maks;
  // cout << lcaf(4,3);
  // cout << lcaf(5,4);
  // cout << lcaf(1,2);
}
