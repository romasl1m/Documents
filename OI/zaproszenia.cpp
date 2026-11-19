#include <iostream>
using namespace std;
int a[15'001], b[15'001];
int nwz[2][15'001];
int memo[15'001];
int prea[15'001], preb[15'001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m; 
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> b[i];
  }
  for(int i = 1; i <= n; i++){
    int cur = a[i];
    int last = 0;
    for(int j = 1; j <= n; j++){
      if(a[j] == cur){
        prea[j] = last;
        last = j;
      }
    }
  }
  for(int i = 1; i <= m; i++){
    int cur = b[i];
    int last = 0;
    for(int j = 1; j <= m; j++){
      if(b[j] == cur){
        preb[j] = last;
        last = j;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    nwz[i % 2][0] = 0;
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j] and prea[i] > 0 and preb[j] > 0){
        nwz[i % 2][j] = memo[preb[j]] + 2;
      }else{
        nwz[i % 2][j] = 0;
      }
      nwz[i % 2][j] = max(nwz[i % 2][j], max(nwz[(i - 1) % 2][j],nwz[i % 2][j - 1]));
    }
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j]){
        memo[j] = nwz[(i - 1) % 2][j - 1];
      }
    }
  }
  cout << nwz[n % 2][m];
}
