#include <iostream>
using namespace std;
int main(){
  int n = 50'000; int k = 100'000;
  cout << n << " " << k << "\n";
  for(int i = 1; i < n; i++){
    cout << i << " " << i + 1 << "\n";
  }
  while(k--){
    cout << 1 << " " << n << "\n";
  }
  return 0;
}
