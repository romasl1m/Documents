#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct s{
    int x, id;
};
vector<s> wec[100'001];
int low[100'001], pre[100'001];
// int out[100'001];
bool wiz[100'001];
int cur = 0;
bool mst[100'001];
int com = 0;
int comp[100'001];
vector<int> tree[100'001];
long long sub[100'001]; 
bool wiz2[100'001];
void most(int w, int p){
  wiz[w] = true;
  pre[w] = cur;
  low[w] = cur++;
  for(auto ss : wec[w]){
    if(ss.x == p) continue;
    if(wiz[ss.x]){
      low[w] = min(low[w], pre[ss.x]);
    }
    else{
      most(ss.x, w);
      low[w] = min(low[w], low[ss.x]);
      if(low[ss.x] > pre[w]){
          mst[ss.id] = true; 
      }
    }
  }
}
void compf(int w){
  comp[w] = com;
  for(auto ss : wec[w]){
    if(comp[ss.x] == 0 and not mst[ss.id]){
      compf(ss.x);
    }
  }
}
void ftree(int w){
  wiz2[w] = true;
  sub[w] = 0;
  for(int ss : tree[w]){
    if(not wiz2[ss]){
      ftree(ss);
      sub[w] += sub[ss];
    }
  }
  if(sub[w] == 0) sub[w] = 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      wec[a].push_back({b,i});
      wec[b].push_back({a,i});
    }
    for(int i = 1; i <= n; i++){
      if(wiz[i]) continue;
      most(i, -1);
    }
    for(int i = 1; i <= n; i++){
      if(comp[i] == 0){
        com++;
        compf(i);
      }
    }
    for(int i = 1; i <= n; i++){
      for(auto ss : wec[i]){
        if(comp[i] == comp[ss.x]) continue;
        tree[comp[i]].push_back(comp[ss.x]);
      }
    }
    for(int i = 1; i <= com; i++){
      for(int ss : tree[i]){
        cout << ss << " ";
      }
      cout << endl;
    }
    vector<long long> siz(com + 1);
    for(int i = 1; i <= n; i++){
      siz[comp[i]]++;
    }
    for(int i = 0; i <= com; i++){
      cout << siz[i] << " ";
    }
    for(int i = 1; i <= com; i++){
      sub[i] = siz[i];
    }
    long long cur = 0;
    for(int i = 1; i <= com; i++){
      if(not wiz2[i]){
        ftree(i);
      }
    }
    for(int i = 1; i <= com; i++){
      for(int ss : tree[i]){
        if(pre[i] < pre[ss]){ 
          long long s = min(sub[i], sub[ss]);
          cur += s * (n - s);
        }
      }
    }
    long long res =  (long long)(n * (n - 1));
    cout << res - cur;

    return 0;
}
