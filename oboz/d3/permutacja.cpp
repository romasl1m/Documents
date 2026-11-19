#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> wec[100'001];
bool wiz[100'001];
int cur = 0;
int tab[100'001];
int freq[100'001];
bool comp(int a, int b){
  return a > b;
}
void dfs(int w){
  wiz[w] = true;
  tab[w] = cur;
  for(int ss : wec[w]){
    if(tab[ss] == cur) return;
    dfs(ss);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    wec[i].push_back(x);
  }
  for(int i = 1; i <= n; i++){
    if(wiz[i]) continue;
    // cout << "DFS " << i << endl;
    cur++;
    dfs(i);
  }
  for(int i = 1; i <= n; i++){
    freq[tab[i]]++;
  }
  // for(int i = 1; i <= n; i++){
  //   cout << tab[i] << " ";
  // }
  // cout << endl;
  // for(int i = 1; i <= n; i++){
  //   cout << freq[i] << " ";
  // }
  // cout << endl;
  sort(freq + 1, freq + n + 1, comp);
  int res = 0;
  for(int i = 1; i <= min(cur,k + 1); i++){
    res += freq[i];
  }
  cout << res;
  return 0;
}
