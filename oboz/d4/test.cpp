#include <iostream>
using namespace std;
int tab[100'001];
int main(){
  srand(time(NULL));
  int n = rand() % 6;
  while(n < 2){
    n = rand() % 6;
  }
  cout << n << "\n";
  int a = rand(), b = rand();
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int x = rand() % 2;
      if(x == 1){
        cout << a << " ";
      }else{
        cout << b << " ";
      }
    }
    cout << "\n";
  }
}
