#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int quan[3];
int pr[3];
int tab[3];
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  long long r;
  for(int i = 0; i < 3; i++) cin >> tab[i];
  for(int i = 0; i < 3; i++) cin >> pr[i];
  cin >> r;
  
  for(char c : s){
    if(c == 'B'){
      quan[0]++;
    }else if(c == 'S'){
      quan[1]++;
    }else{
      quan[2]++;
    }
  } 

  long long l = 0, ri = r + 1'000;
  while(l < ri){
    long long mid = (l + ri + 1) >> 1;
    long long cur = 0;
    for(int i = 0; i < 3; i++){
      cur += (max((long long) 0,(mid * quan[i]) - tab[i])) * pr[i];
    }
    if(cur > r){
      ri = mid - 1;
    }else{
      l = mid;
    }
  }
  cout << l << "\n";
}
