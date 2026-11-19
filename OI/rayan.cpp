#include <iostream>
#include <stack>
using namespace std;
int tab[500'001];
int lower[500'001];
int higher[500'001];
int res[500'001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<int> s;
  for(int i = 0; i < n; i++){
    cin >> tab[i];
  }
  for(int i = 0; i < n; i++){
    while(not s.empty() and tab[s.top()] >= tab[i]){
      s.pop();
    }
    if(s.empty()){ 
      s.push(i);
      lower[i] = -1;
      continue;
    }
    lower[i] = s.top();
    s.push(i);
  }
  while(not s.empty()){
    s.pop();
  }
  for(int i = n - 1; i >= 0; i--){
    while(not s.empty() and tab[s.top()] >= tab[i]){
      s.pop();
    }
    if(s.empty()){
      s.push(i);
      higher[i] = n;
      continue;
    }
    higher[i] = s.top();
    s.push(i);
  }

  for(int i = 0; i < n; i++){
    int cur = higher[i] - lower[i] - 1;
    res[cur] = max(res[cur], tab[i]);
  }
  for(int i = n - 1; i >= 1; i--){
    res[i] = max(res[i], res[i + 1]);
  }
  for(int i = 1; i <= n; i++){
    cout << res[i] << " ";
  }
}
