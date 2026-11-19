#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int tab[1'000'001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int maks = 0, res = 0, i = 0;
  for(int i = 0; i < n; i++){
    cin >> tab[i]; 
  }
  while(i < n){
    stack <int> s;
    maks = 0;
    vector<int> pref;
    while(i < n){
      while(not s.empty() and s.top() < tab[i]){
        maks = max(maks, s.top());
        s.pop();
      }
      if(tab[i] < maks) break;
      s.push(tab[i]);
      pref.push_back(tab[i]);
      i++;
    }
    res++;
  }
  cout << res;
}
