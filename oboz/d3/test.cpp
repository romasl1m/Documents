#include <iostream>
using namespace std;
long long tab[502][502];
int main(){
  srand(time(NULL));
  int n = rand() % 501;
  int m = rand() % 501;
  cout << 0 << " " << n << " " << m << "\n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      long long cur = rand();
      while(tab[i - 1][j] == cur or tab[i + 1][j] == cur or tab[i][j + 1] == cur or tab[i][j - 1] == cur or cur == 0){
        cur = rand();
      }
      tab[i][j] = cur;
      cout << cur << " ";
    }
    cout << "\n";
  }
  return 0;
}
