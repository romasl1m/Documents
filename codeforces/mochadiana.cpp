#include <iostream>
#include <vector>
using namespace std;
int tab[1001];
int tab0[1001];
int siz[1001];
int siz0[1001];
int find(int w){
  if(tab[w] != w){
    return find(tab[w]);  
  }
  return w;
}
int find0(int w){
  if(tab0[w] != w){
    return find0(tab0[w]);
  }
  return w;
}
void unio(int x, int y){
  y = find(y); x = find(x);  
  if(x == y) return;
  if(siz[y] > siz[x]){
    swap(x,y);
  }
  siz[x] += siz[y];
  tab[y] = x;
}
void unio0(int x, int y){
  y = find0(y); x = find0(x);  
  if(x == y) return;
  if(siz0[y] > siz0[x]){
    swap(x,y);
  }
  tab0[y] = x;
  siz0[x] += siz0[y];
}
vector<int> wec[1001];
vector<int> wec0[1001];
int main(){
  int n,m1, m2;
  cin >> n >> m1 >> m2;
  for(int i = 1; i <= n; i++){
    siz[i] = siz0[i] = 1;
    tab0[i] = tab[i] = i;
  }
  for(int i = 0; i < m1; i++){
    int a,b;
    cin >> a >> b;
    wec[a].push_back(b);
    wec[b].push_back(a);
    unio(a,b);
  }
  for(int i = 0; i < m2; i++){
    int a,b;
    cin >> a >> b;
    wec0[a].push_back(b);
    wec0[b].push_back(a);
    unio0(a,b);
  }
  vector<pair<int,int>> cur;
  int res = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(find(i) != find(j) and find0(j) != find0(i)){
        res++;
        unio(i,j);
        unio0(i,j);
        cur.push_back({i,j});
      }
    }
  }   
  cout << res << "\n";
  for(int i = 0; i < res; i++){
    cout << cur[i].first << " " << cur[i].second << "\n";
  }
}
