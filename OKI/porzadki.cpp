#include <iostream>
#include <cstdio>
using namespace std;
long long n;
long long smaller[10'001], bigger[10'001];
int tab[10'001];
long long inversions[10'001];
const int base = 10'001;
int tree[40'001];
void findf(int ind){
  int w = 1;
  while(tree[w] > ind){
    if(ind > tree[w << 1]){
      w <<= 1;
    }else{
      w <<= 1;
      w |= 1;
    }
  }
}
void f(int a, int b){
    printf("%d %d\n", a, b);
    fflush(stdout);
    long long cur;
    scanf("%lld", &cur);
    inversions[b] = cur;
    smaller[b] = (cur + n - 2) >> 1;
    tab[b] = findf(smaller[b]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      f(1,i);
    }
}
