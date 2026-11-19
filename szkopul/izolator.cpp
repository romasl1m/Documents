#include <iostream>
#include <algorithm>
using namespace std;
long long tab[100'001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> tab[i];
  }
  long long res = 0;
  sort(tab, tab + n);
  for(int i = 0; i < n >> 1; i++){
    res += tab[n - i - 1] - tab[i];
  }
  for(int i = 0; i < n; i++){
    res += tab[i];
  }
  cout << res;
  return 0;
}
