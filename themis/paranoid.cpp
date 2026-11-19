#include <iostream>
#include <vector>
using namespace std;
void f(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long cur = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 or s[i] == s[i - 1]){
      cur += 1;
    }else{
      cur += i + 1;
    }
  }
  cout << cur << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--){
    f();
  }
  return 0;
}
