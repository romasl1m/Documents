#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tab[100'001];
const int base = 100'001;
int wec[base << 2];
void add(int w, int l, int r){
  if(l == r){
    wec[w] = tab[l];
    return;
  } 
  int mid = (l + r) >> 1;
  add(w << 1, l, mid);
  add((w << 1) | 1, mid + 1, r);
  wec[w] = wec[w << 1] + wec[(w << 1) | 1];
}
int minf(int w, int l, int r, int a, int b, int k){
  if(r < a or b < l){
    return 0;
  } 
  if(a <= l and r <= b){
    return wec[w];
  }
  int mid = (l + r) >> 1;
  return minf(w << 1, l, mid, a, b, k) + minf((w << 1) | 1, mid + 1, r, a, b, k);
}
int bin2(int n,int l, int r, int k){
    int low = 0, high = 1e9;
    while(low < high){
      int mid = (low + high) >> 1;
      int c = minf(1, 1, n, l, r, mid);
      if(c >= k) high = mid;
      else low = mid + 1;
    }
    return low;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> tab[i];
  }
  add(1, 1, n);
  while(q--){
    int l,r,m,k;
    cin >> l >> r >> m >> k;
    int p = l + k + m - 2;
    if(p > r){
      cout << bin2(n,l,r,k) << "\n";
      continue;
    }
    cout << min(bin2(n,l, p, k), tab[p]) << "\n";
  }
}
