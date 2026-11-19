#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> wec(n);
    int maks = 0, cur = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      wec[i] = x;
      if(x > wec[maks]){
        maks = i;
      }
      if(x == wec[maks]){
        cur++;
      }
    }
    if(cur > 1){
      swap(wec[maks], wec[0]);
    }
    for(int i = 0; i < n; i++){
      cout << wec[i] << " ";
    }
    cout << "\n";
  }
}
