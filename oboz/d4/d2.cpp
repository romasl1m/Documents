#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[200'001];
int dist[200'001];
void dfs(int w){
  wiz[w] = true;
  for(int ss : wec[w]){
    if(wiz[ss]) continue;
    dist[ss] = dist[w] + 1;
    dfs(ss);
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
  }
  // if(n <= 50){
  //   brut();
  //   return 0;
  // }
  dfs(1); 
}
