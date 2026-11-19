#include <iostream>
using namespace std;
int main(){
  int n = rand() % 141;
  int a = rand(), b = rand();
  cout << n << "\n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int cur = rand() % 2;
      if(cur == 1){
        cout << b << " ";
      }else{
        cout << a << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
