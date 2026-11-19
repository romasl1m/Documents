#include <iostream>
#include <vector>
using namespace std;
struct s{
  int a,b; long long c;
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<long long> tab(n + 2);
  for(int i = 1; i <= n; i++){
    cin >> tab[i];
  }
  vector<s> wec(m + 1);
  for(int i = 1; i <= m; i++){
    int a,b; long long c;
    cin >> a >> b >> c;
    wec[i] = {a,b,c};
  }
  vector<long long> pref(m + 2);
  while(k--){
    int a,b;
    cin >> a >> b;
    pref[a]++;
    pref[b + 1]--;
  }
  for(int i = 1; i <= m; i++){
    pref[i] += pref[i - 1];
  }
  vector<long long> dif(n + 2);
  for(int i = 1; i <= m; i++){
    long long cur = wec[i].c * pref[i];
    dif[wec[i].a] += cur;
    dif[wec[i].b + 1] -= cur;
  }
  for(int i = 1; i <= n; i++){
    dif[i] += dif[i - 1];
    tab[i] += dif[i];
  }
  for(int i = 1; i <= n; i++){
    cout << tab[i] << " ";
  }
}
