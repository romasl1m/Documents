#include <iostream>
#include <vector>
using namespace std;
struct s{
  int a,b,c;
};
vector<int> tab[100'001];
int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    tab[a].push_back(b);
  }
  vector<s> wec;
  for(int i = 1; i <= n - 2; i++){
    for(int j = i + 1; j <= n - 1; j++){
      for(int k = j + 1; k <= n; k++){
        wec.push_back({i,j,k});
      }
    }
  }
  cout << wec.size() << 1;
}
