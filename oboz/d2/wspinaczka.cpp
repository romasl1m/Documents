#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[5'001];
int gre[5'001];
int low[5'001];
int par[5'001];
//1 lower 2 greater 0 none
void dfs(int w, int p, int gr){
  // if(low[w] != 0 or gre[w] != 0) return ;
  // cout << w << " ";
  if(gr == 1){
    for(int ss : wec[w]){
      if(par[ss] == p) continue;

      // cout << ss << " " << w << low[ss] << " " << low[w] + 1 << endl;
      if(ss < w and low[ss] < low[w] + 1){
        par[ss] = w;
        low[ss] = low[w] + 1;
        dfs(ss,w, gr);
      }
    }
  }else if(gr == 2){
    for(int ss : wec[w]){
      // cout << "2 " << w << " " << ss << endl;
      if(par[ss] == w) continue;
      if(ss > w and gre[ss] < gre[w] + 1){
        // cout << "PASS" << w << " " << ss << endl;
      // cout << ss << " " << w << gre[ss] << " " << gre[w] + 1 << endl;
        par[ss] = w;
        gre[ss] = gre[w] + 1;
        dfs(ss,w,gr);
      }else if(ss < w and low[ss] < gre[w] + 1){
        par[ss] = w;
        low[ss] = gre[w] + 1;
        dfs(ss,w,1);
      }
    }
  }else{
    for(int ss : wec[w]){
      if(ss > w){

      // cout << ss << " " << w << gre[ss] << " " << gre[w] + 1 << endl;
        par[ss] = w;
        gre[ss] = gre[w] + 1;
        // cout << "DFS " << ss << " " << w << " ";
        dfs(ss, w,2);
      }else{
      // cout << ss << " " << w << low[ss] << " " << low[w] + 1 << endl;
        low[ss] = low[w] + 1;
        par[ss] = w;
        dfs(ss, w,1);
      }
    }
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
  }
  int res = 0;
  for(int i = 1; i <= n; i++){
    dfs(i,0,0);
    cout << "End" << endl << endl;
    for(int j = 1; j <= n; j++){
      res = max(res, gre[j]);
      res = max(res, low[j]);
      cout << low[j] << " " << gre[j] << endl;
      low[j] = 0;
      gre[j] = 0;
      par[j] = 0;
    }
    // return 0;
  }
  cout << res << " ";
}
