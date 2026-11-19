#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<pair<int, int>> wec[100'001];
int comp[100'001], par[100'001];
int tab[1'000'001];
bool wiz[100'001], wiz2[100'001], wiz3[100'001];
vector<vector<pair<int,int>>> ord;
int cur = -1;
void dfs(int w){
  comp[w] = cur;
  wiz[w] = true;
  for(auto [ss, i] : ord[w]){
    if(wiz[ss] or tab[i] == 1) continue;
    par[ss] = w; dfs(ss);
  }
}
void mst(int w1, int n){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  vector<bool> wiz1(n + 1);
  vector<int> dist(n + 1, 1e9);
  vector<pair<int,int>> order;
  q.push({0, w1});
  dist[w1] = 0;
  order.push_back({w1,0});
  while(not q.empty()){
    int w = q.top().second;
    q.pop();
    for(auto [ss, i] : ord[w]){
      if(wiz[ss] or dist[ss] > dist[w] + 1) continue;
      dist[ss] = dist[w] + 1;
      order.push_back({ss,i});
      q.push({dist[ss], ss});
    }
  }
  for(int i = 1; i < order.size();i++){
    if(wec[i].size() % 2 == 0) continue;
    wec[order[i].first].push_back({order[i - 1].first, order[i].second});
    wec[order[i - 1].first].push_back({order[i].first, order[i].second});
  } 
}
void euler(){
  stack<int> s;
  s.push(1);
  queue<int> q;
  while(not s.empty()){
    int w = s.top();
    if(wec[w].empty()){
      s.pop();
      continue;
    } 
    auto [ss, i] = wec[w].back();
    wec[w].pop_back();
    s.push(ss);
    q.push(i);
  }
  cout << q.size() << "\n";
  while(not q.empty()){
    cout << q.front() + 1 << " "; q.pop();
  }
}
void f(int n){
  for(int i = 1; i <= n; i++){
    if(not wiz2[comp[i]]) mst(i, n);
  }
  euler();
} 
int main(){
  int n,m;
  cin >> n >> m;
  ord.resize(n + 1);
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    wec[a].push_back({b,i});
    wec[b].push_back({a,i});
    tab[i] = c;
    if(c == 2){
      ord[a].push_back({b,i});
      ord[b].push_back({a,i});
    }
  }
  for(int i = 1; i <= n; i++){
    if(not wiz[i]){
      cur++;
      dfs(i);
    }
  }
  f(n);
}
