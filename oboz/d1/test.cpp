#include <iostream>
#include <vector>
using namespace std;
int main(){
  srand(time(NULL));
  long long n = rand() % 200'001;
  vector<long long> wec(n);
  long long d = 0;
  for(int i = 0; i < n; i++){
    long long cur = rand();
    wec[i] = cur;
    d += cur;
  }
  cout << d << " " << n << " ";
  for(int i = 0; i < n; i++){
    cout << wec[i] << " ";
  }
  return 0;
}
