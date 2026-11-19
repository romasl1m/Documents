#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
bool wiz[1'501];
int scc[1'501];
int cur = 0;
vector<int> ord;
vector<int> wec[1'501];
vector<int> rew[1'501];
vector<int> dag[1'501];
bitset<1'501> bits[1'501];
int rep[1'501];
void dagf(int n){
  for(int i = 1; i <= n; i++){
    int w = scc[i];
    for(int ss : wec[i]){
      if(scc[ss] == w) continue;
      dag[w].push_back(scc[ss]);
    }
  } 
}
// bool wiz1[1'501];
// vector<int> ord1;
// void dfs2(int w){
//   wiz1[w] = true;
//   for(int ss : dag[w]){
//     if(wiz1[ss]) continue;
//     dfs2(ss);
//   }
//   ord1.push_back(w);
// }
void f(int n){
  for(int i = 0; i < cur; i++){
    bits[i][i] = 1;
  }
  for(int i = 0; i < cur; i++){
      for(int ss : dag[i]){
          bits[i].set(ss);
      }
  } 
  for(int i = 0; i < cur; i++){
    for(int j = 0; j < cur; j++){
        if(bits[j].test(i)) bits[j] |= bits[i];
    } 
  }
}
void dfs(int w){
  wiz[w] = true;
  for(int ss : wec[w]){
    if(wiz[ss]) continue;
    dfs(ss);
  }
  ord.push_back(w);
}
void dfs1(int w){
  wiz[w] = true;
  scc[w] = cur;
  for(int ss : rew[w]){
    if(scc[ss] >= 0) continue;
    dfs1(ss);
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
    wec[a].push_back(b);
    rew[b].push_back(a);
    // bits[a].set(b);
  }
  for(int i = 1; i <= n; i++){
    if(wiz[i]) continue;
    dfs(i);
  }
  for(int i = 1; i <= n; i++){
    scc[i] = -1;
  }
  for(int i = n - 1; i >= 0; i--){
    if(scc[ord[i]] >= 0) continue;
    dfs1(ord[i]);
    rep[cur] = ord[i];
    cur++;
  }
  dagf(n);
  f(n);
  long long res = ((cur + 2) * (cur - 1)) >> 1;
  vector<pair<int, int>> resw;
  for(int i = 0; i < cur; i++){
      for(int j = cur - 1; j >= 0; j--){
          if(i == j) continue;
          if(bits[i].test(j)) continue;
          resw.push_back({rep[i], rep[j]});
          bits[i] |= bits[j];
      }
  }
  cout << resw.size() << "\n";
  for(auto ss : resw){
    cout << ss.first << " " << ss.second << "\n";
  }
}
