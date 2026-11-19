#include <iostream>
#include <vector>
using namespace std;
int n;
int subtree[200'001];
bool wiz[200'001];
vector<int> wec[200'001];
long long f(long long x){
  if((x & 1) == 0){
    return x + (x >> 1);
  }else{
    return x + (x >> 1) + 1;
  }
}
void dfs(int w){
  wiz[w] = true;
  for(int ss : wec[w]){
    if(wiz[ss]) continue;
    dfs(ss);
    subtree[w] += subtree[ss];
  }
  subtree[w]++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
      int x;
      cin >> x;
      wec[x].push_back(i);
    }
    for(int ss : wec[0]){
      dfs(ss);
    }
    long long res = 0;
    for(int i = 1; i <= n; i++){
      if(subtree[i] == 1){
        res++;
        continue;
      }
      long long minsub = 0;
      for(int ss : wec[i]){
        minsub = max(minsub, (long long)subtree[ss]);
      }
      res += f(minsub);
    }
    cout << k / res;
    return 0;
}
