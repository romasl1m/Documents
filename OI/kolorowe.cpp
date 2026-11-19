#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int tab[400'001];
vector<int> wec[400'001];
bool wiz[200'001];
stack<int> q;
struct x{
  int w, par, dep, idx;
};
bool dfs(int w, int n){
  stack<x> s;
  s.push({w, -1, 1, 0});
  while(not s.empty()){
    x &cur = s.top();
    if(cur.idx == 0){ 
      wiz[tab[cur.w]] = true;
      q.push(cur.w);
      if(cur.dep == n){
        return true;
      }
    }
    if(cur.idx < (int)wec[cur.w].size()){
      int ss = wec[cur.w][cur.idx++];
      if(ss == cur.par or wiz[tab[ss]]) continue;
      s.push({ss, cur.w, cur.dep + 1, 0});
    }
    else{
      wiz[tab[cur.w]] = false;
      q.pop();
      s.pop();
    }
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int z;
  cin >> z;
  while(z--){
    int n;
    cin >> n;
    for(int i = 1; i <= (n << 1); i++){
      wec[i].clear();
    }
    for(int i = 0; i < n; i++) wiz[i] = false;
    while(not q.empty()) q.pop();
    for(int i = 1; i < (n << 1); i++){
      int a,b;
      cin >> a >> b;
      wec[a].push_back(b);
      wec[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
      int a,b;
      cin >> a >> b;
      tab[a] = tab[b] = i;
    }
    bool ok = false;
    for(int i = n << 1; i > 0; i--){
      if(dfs(i, n)){
        ok = true;
        cout << "TAK\n";
        vector<bool> res((n << 1) | 1, false);
        while(not q.empty()){
          res[q.top()] = true;
          q.pop();
        }
        for(int i = 1; i <= (n << 1); i++){
          cout << res[i] << " ";
        }
        cout << "\n";
        break;
      }
    }
    if(not ok) cout << "NIE\n";
  }
}
