#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct s{
  int a,b;
};
vector<s> wec[1'000'001];
bool wiz[1'000'001];
vector<pair<int,int>> roads;
int in[1'000'001], low[1'000'001];
int par[1'000'001];
bool block[1'000'001];
int cur = 0;
void dfs(int w, int p){
  wiz[w] = true;
  in[w] = low[w] = ++cur;
  for(auto ss : wec[w]){
    if(ss.b == p) continue;
    if(in[ss.a]){
      low[w] = min(low[w], in[ss.a]);
      continue;
    }
    dfs(ss.a, ss.b);
    low[w] = min(low[w], low[ss.a]);
    if(low[ss.a] > in[w]){
      block[ss.b] = true;
    }
  } 
}
void lookin4parents(int w){
  wiz[w] = true;
  for(auto ss : wec[w]){
    if(wiz[ss.a] or block[ss.b]) continue;
    par[ss.a] = w;
    lookin4parents(ss.a);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back({b,i});
    wec[b].push_back({a,i});
    roads.push_back({a,b});
  }
  for(int i = 1; i <= n; i++){
    if(wiz[i]) continue;
    dfs(i, 0);
  }
  for(int i = 1; i <= n; i++) wiz[i] = false;
  int ssc = 0;
  for(int i = 1; i <= n; i++){
    if(wiz[i]) continue;
    ssc++;
    lookin4parents(i);
  }
  cout << ssc << "\n";
  for(int i = 0; i < m; i++){
    int w = roads[i].first, ss = roads[i].second;
    if(w == par[ss]){
      cout << '>';
    }else{
      cout << '<';
    }
  } 
}
