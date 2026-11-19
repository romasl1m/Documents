#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> tab;
vector<int> surn;
int n;
int base;
const int maks = 1e9 + 7;
const int p = 31;
int ps[1 << 20 | 1];
int siz[20];
void f2(int b, char c){
  int w = b + base;
  surn[w] = c - 'a';
  int level = 0;
  w >>= 1;
  while(w > 0){
    int a = surn[w << 1], b = surn[(w << 1) | 1];
    if(a > b){
      swap(a,b);
    }
    surn[w] = (1LL * a * ps[siz[level]] + b) % maks;
    level++;
    w >>= 1;
  }
}
void build2(){
  for(int i = 1; i <= n; i++){
    int length = siz[i - 1];
    for(int j = base >> i; j < base >> (i - 1); j++){
      int a = surn[j << 1], b = surn[(j << 1) | 1];
      if(a > b){
        swap(a,b);
      }
      surn[j] = (1LL * a * ps[siz[i - 1]] + b) % maks;
    }
  }
}
void f(int b, char c){
  int w = b + base; 
  tab[w] = c - 'a';
  w >>= 1;
  int level = 0;
  while(w > 0){
    int a = tab[w << 1], b = tab[(w << 1) | 1];
    if(a > b){
      swap(a,b);
    }
    tab[w] = (1LL * a * ps[siz[level]] + b) % maks;
    level++;
    w >>= 1;
  }
}
void build(){
  for(int i = 1; i <= n; i++){
    int length = siz[i - 1];
    for(int j = base >> i; j < (base >> (i - 1)); j++){
      int a = tab[j << 1], b = tab[(j << 1) | 1];
      if(a > b){
        swap(a,b);
      }
      tab[j] = (1LL * a * ps[siz[i - 1]] + b) % maks;
    }
  }
}
int main(){
  int q;
  cin >> n >> q;
  ps[0] = 1;
  for(int i = 1; i <= 1 << n; i++){
    ps[i] = (ps[i - 1] * p) % maks;
  }
  base = (1 << n);
  tab.resize(base << 1, 0);
  surn.resize(base << 1, 0);
  for(int i = 1; i <= base; i++){
    char c;
    cin >> c;
    surn[i + base] = c - 'a';
  }
  siz[0] = 1;
  for(int i = 1; i <= n; i++){
    siz[i] = siz[i - 1] << 1;
  }
  for(int i = 1; i <= base; i++){
    char c;
    cin >> c;
    tab[i + base] = c - 'a';
  }
  build();
  build2();
  while(q--){
    int a,b; char c;
    cin >> a >> b >> c;
    if(a == 1){
      f2(b,c);
    }else{
      f(b, c);
    }
    if(tab[1] == surn[1]){
      cout << "TAK\n";
    }else{
      cout << "NIE\n";
    }
  }
}
