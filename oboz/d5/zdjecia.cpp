#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tab[5][100'001];
bool comp(int a, int b){
  int cur = 0;
  for(int i = 0; i < 5; i++){
    if(tab[i][a] < tab[i][b]){
      cur++;
    }
  }
  if(cur >= 3) return true;
  return false;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < n; j++){
      int x;
      cin >> x;
      tab[i][x] = j;
    }
  }
  vector<int> wec(n);
  for(int i = 0; i < n; i++){
    wec[i] = i + 1;
  }
  sort(wec.begin(), wec.end(), comp);
  for(int i = 0; i < n; i++){
    cout << wec[i] << " ";
  }
}
