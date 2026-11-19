#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[500'001];
int tab[500'001];
int par[500'001];
bool blocked[500'001];
int res = 1;
void f(int w){
  if(w > 0){
    blocked[w] = true;
    if(par[w] > 0 and blocked[par[w]]) res--;
    res += wec[w].size() - tab[w] - 1;
    tab[par[w]]++;
  }else{
    w = -w;
    blocked[w] = false;
    if(par[w] > 0 and blocked[par[w]]) res++;
    res -= wec[w].size() - tab[w] - 1;
    tab[par[w]]--;
  }
}
void dfs(int w, int p){
  for(int ss : wec[w]){
    if(ss == p) continue;
    par[ss] = w;
    dfs(ss,w);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
  }
  dfs(1,0);
  int q;
  cin >> q;
  while(q--){
    int cur;
    cin >> cur;
    f(cur);
    cout << res << "\n";
  }
  return 0;
}
