#include <iostream>
#include <algorithm>
using namespace std;
pair<long long, long long> tab[500'001];
void f(){
    
}
int main(){
  int n; long long W;
  cin >> n >> W;
  for(int i = 0; i < n; i++){
    long long w,m;
    cin >> w >> m;
    tab[i] = {m,w};
  }
  sort(tab, tab + n);
  int i = 0;
  while(tab[i].first == tab[0].first and W % 2){
    
  }
}
