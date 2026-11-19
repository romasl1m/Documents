#include <iostream>
using namespace std;
int tab[21];
int n;
bool check(int cur){
  int pos = 1;
  for(int i = 1; i <= n; i++){
    if((pos + cur - 1) % (n - i + 1) ){
      pos = tab[i];
      for(int j = pos + 1; j <= n - i + 1; j++){
        tab[i - 1] = tab[i];
      }
      continue;
    }
    return false;
  }
  return true;
}
int main(){
  cin>> n;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    tab[x] = i;
  }
  int start = tab[1];
  while(not check(start)){
    start += n;
  }
  cout << start;
  return 0;
}
