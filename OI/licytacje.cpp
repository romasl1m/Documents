#include <iostream>
#include <vector>
using namespace std;
pair<long long,long long> tab[501];
long long dp[501][1001];
long long d[501][1001];
pair<long long, long long> cup[1001];
const int mod = 1e9 + 7;
long long great(pair<long long> l, int r){
  
}
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> tab[i].first >> tab[i].second;
  }
  for(int i = 0; i < n - 1; i++){
    cup[i] = {tab[i].second, tab[i + 1].second};
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(cup[j].first > tab[i].second or tab[i].first > cur[j].second){
        dp[i][j] = 0;
      }else{
        int auct = 0;
        for(int k = i; k >= 0; k--){
          if(cup[j].first > tab[k].second or tab[k].first > cup[j].second) continue;
          auct++;
        }
        dp[]
      }
    }
  }
  return 0;
}
