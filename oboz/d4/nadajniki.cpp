#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[200'001];
int tab[200'001];
int cur = 0;
int dfs(int w, int p, bool ok){
  if(not ok) return 1;
  int res = 0;
  for(int ss : wec[w]){
    if(ss == p) continue;
    res += dfs(ss, w, false);
  }
  return res + 1;
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
  for(int i = 1; i <= n; i++){

  }
}
