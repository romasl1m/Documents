#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n,m;
struct s{
  int x,id;
};
vector<s> wec[100'001];
int low[100'001];
int sc[100'001];
int pre[100'001];
bool art[100'001];
bool wiz[100'001];
stack<pair<int,int>> st; // Renamed from 's' to 'st' because 's' is already used for struct name
int cur = 0;
int com = 1;
int comp[100'001];
int mst[200'001];
void dfs2(int w){
  comp[w] = com;
  for(auto ss : wec[w]){
    if(comp[ss.x] == 0 and not mst[ss.id]){
      dfs2(ss.x);
    }
  }
}
void dfs1(int w, int p){
  wiz[w] = true;
  pre[w] = low[w] = cur++;
  for(auto ss : wec[w]){
    if(ss.x == p) continue;
    if(wiz[ss.x]){
      low[w] = min(low[w], pre[ss.x]);
    }
    else{
      dfs1(ss.x, w);
      low[w] = min(low[w], low[ss.x]);
      if(low[ss.x] > pre[w]){
        mst[ss.id] = true; 
      }
    }
  }
}
int main(){
  if (!(cin >> n >> m)) return 0;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back({b,i});
    wec[b].push_back({a,i});
  }
  for(int i = 1; i <= n; i++){
    if(wiz[i]) continue;
    dfs1(i,-1);
  }
  long long res = (long long)n * (n - 1);
  for(int i = 1; i <= n; i++){
    if(comp[i] == 0){
      dfs2(i);
      com++;
    }
  }
  vector<int> rozm(com);
  for(int i = 1; i <= n; i++){
    rozm[comp[i]]++;
  }
  for(int i = 1; i < com; i++){
    cout << "Component " << i << " size: " << rozm[i] << endl;
  }
  for(int i = 1; i < com; i++){
    res -= (long long)rozm[i] * (rozm[i] - 1);
  }
  cout << "Result: " << res << endl;
  return 0;
}
