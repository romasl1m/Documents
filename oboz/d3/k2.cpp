#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,int>> wec;
long long res = 0;
int n,h;
set<pair<int,int>> s;
int f(){
  for(int i = 1; i <= n; i++){
    int l = wec[i].first, r = wec[i].second;
    vector<pair<int,int>> rem, add;
    // cout << "UB " << s.upper_bound({l,-1})->second << " " << s.upper_bound({-1,r})->second << " " << s.upper_bound({-1,l})->second << " " << s.upper_bound({r,-1})->second << endl;
    // return 0;
    
    auto st = s.lower_bound({l + 1, -1});
    if(st != s.begin()) st--;
    for(auto cur = st; cur != s.end() and cur->first <= r; cur++){
      if(cur->second < l) continue;
      rem.push_back(*cur);
      if(cur->first < l) add.push_back({cur->first, l});
      if(cur->second > r) add.push_back({r, cur->second});
    }

    //
    // for(auto cur = s.upper_bound({l,-1}); cur != s.upper_bound({-1,r}); cur++){
    //   if(cur->first > r or cur->second < l) continue;
    //   rem.push_back(*cur);
    //   if(cur->first < l){
    //     add.push_back({cur->first, l});
    //   }
    //   if(cur->second > r){
    //     add.push_back({r, cur->second});
    //   }
    // }
    for(auto cur : rem){
      s.erase(cur);
    }
    for(auto cur : add){
      s.insert(cur);
    }
    // cout << "END " << i << " \n";
    // for(auto ss : s){
    //   cout << ss.first << " " << ss.second << endl;
    // }
    if(s.empty()){
      res += 2;
      if(l == 0){
        s.insert({r, h});
      }else if(r == h){
        s.insert({0,l});
      }else{
        s.insert({0,l});
        s.insert({r, h});
      }
    }
  }
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> h;
  wec.resize(n + 1);
  for(int i = 1; i <= n; i++){
    int x,y;
    cin >> x >> y;
    wec[n - i + 1] = {x,y};
  }
  cout << f();
  return 0;
}
