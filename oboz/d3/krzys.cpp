#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> wec;
long long res = 0;
int n,h;
int wall(int cur){
  if(cur > n) return 1e9;
  if(wec[cur].second == h){
    return 2;
  }
  if(wec[cur].first == 0){
    return 1;
  }
  return 0;
}
int main(){
  cin >> n >> h;
  wec.resize(n + 1);
  for(int i = 1; i <= n; i++){
    int x,y;
    cin >> x >> y;
    wec[n - i + 1] = {x,y};
  }
  int cur = 1;
  while(cur < n){
    int w = wall(cur);
    if(w == 1e9) break;
    if(w == 2){
      res += 2;
      int i = cur + 1;
      while(i <= n and wall(i) != 1){
        i++;
      } 
      cur = i;
    }

    else if(w == 1){
      res += 2;
      int i = cur + 1;
      while(i <= n){
        if(wall(i) == 2){
          if(wec[cur].second >= wec[i].first){
            break;
          }
        }
        i++;
      }
      cur = i;
    }

    else{
      int i = cur + 1;
      int dir = 0;
      while(i <= n and wall(i) == dir){
        i++;
      }
      dir = wall(i);
      if(dir == 1) dir = 2;
      else dir = 1;
      while(i <= n and wall(i) != dir){
        i++;
      }
      if(i <= n){
        res += 2;
      }
      cur = i;
    }
    cout << "CURRES " << cur << " " << res << endl;
  }
  if(cur == n){
    res += 2;
  }
  cout << res;
  return 0;
}
