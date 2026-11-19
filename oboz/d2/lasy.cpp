#include <iostream>
using namespace std;
struct point(){
  int x,y;
};
struct event(){
  int add;
  int l,r;
};
vector<pair<point,point>> wec[10'001]; 
int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    if(a > x){
      wec[i] = {{a,b}, {x,y}};
    }
    wec[i] = {{x,y}, {a,b}};
  } 
  point a,b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int minx = min(a.x, b.x), makx = max(a.x, b.x), miny = min(a.y, b.y), maky = max(a.y, b.y);
  int l = 0, r = 100'001;
  while(l < r){
    int mid = (l + r) >> 1;
    vector<event> zam(n << 1 + 2);
    for(int i = 1; i <= n; i++){
      point cur1 = wec[i].first, cur2 = wec[i].second;
      cur1.x -= mid; cur2.x += mid; cur1.y -= mid; cur2.y += mid;
      // zam[i] = {1,{min(a.x, cur1.x + mid), min(a.y, cur1.y + mid}, {max()}};
      zam[i] = {1,max(cur1.x, minx), min(cur2.x, makx)};
      zam[i << 1] = {-1,max}
    }
  }
}
