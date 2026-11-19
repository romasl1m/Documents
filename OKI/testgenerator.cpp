#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    long long s,m;
    cin >> s >> m;
    vector<long long> wec;
    wec.reserve(61);    
    for(int i = m; i > 0; i = (i - 1) & m){
      wec.push_back(i); 
    }
    long long res  = 0;
    for(int i = 0; i < wec.size(); i++){
      if(s >= wec[i]){
        res += s / wec[i];
        s %= wec[i];
      }
    }
    if(s > 0){
      cout << -1 << "\n";
    }else{
      cout << res << "\n"; 
    }
  }
}
