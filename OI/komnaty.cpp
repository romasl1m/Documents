#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[1001];
int wiz[1001];
vector<int> path;
bool wizdfs[1001];
int after[1001];
string instruction;
void dfs(int w){
  int old = w;
  wizdfs[w] = true;
  for(char c : instruction){
    if(c == 'L'){
      w = wec[w][0];
      continue;
    }
    w = wec[w][1];
  }
  after[old] = w;
  if(wizdfs[w]){
    return;
  }
  dfs(w);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m; long long k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++){
    int a,b;
    cin >> a >> b;
    wec[i].push_back(a);
    wec[i].push_back(b);
  }
  cin >> instruction;
  dfs(1);
  int cur = 1, s, t;
  for(int i = 0; 1 == 1; i++){
    if(wiz[cur]){
      s = wiz[cur] - 1;
      t = i;
      break;
    }
    wiz[cur] = i + 1;
    path.push_back(cur);
    cur = after[cur];
  }
  if(k < s){
    cout << path[k];
    return 0;
  }
  cout << path[s + (k - s) % (t - s)];  
  return 0;
}
