#include <iostream>
using namespace std;
bool f(string s1, string s2){
  string s = s1 + s1;
  int res = s.find(s2);
  if(res == string::npos){
    return false;
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  string s1,s2;
  cin >> s1 >> s2;
  if(s1.length() != s2.length() or s1.length() == 1){
    cout << 0;
    return 0;
  }
  if(not f(s1,s2)){
    cout << 0;
    return 0;
  }
  cout << 1;
  return 0;
}
