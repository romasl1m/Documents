#include <iostream>
using namespace std;
const int base = 100'000;
int tab[100'001], dist[100'001], dist1[100'001], tree[base << 1];
void add(int w){
   w += base;
   tree[w] += 1;
   tree[w] %= 2;
   while(w > 1){
     w >>= 1;
     tree[w] = tree[w << 1] + tree[(w << 1) | 1];
   }
}
bool f(int w, int l, int r, int a, int b){
  if(r < a or b < l) return false; 
  if(a <= l and r <= b){
    return tree[w] > 0;
  }
  int mid = (l + r) >> 1;
  return f(w << 1, l, mid, a, b) or f((w << 1) | 1, mid + 1, r, a, b);
}
int main(){
  int x = 0;
  int n,m,q;
  cin >> n >> m >> q;
  for(int i = 0; i < n; i++){
    cin >> tab[i];
  }
  dist[0] = tab[0];
  dist1[0] = tab[0];
  for(int i = 1; i < n; i++){
    int a = m - max(tab[i],tab[i - 1]) + min(tab[i], tab[i - 1]), b = max(tab[i], tab[i - 1]) - min(tab[i - 1], tab[i]);
    b = abs(tab[i] - tab[i - 1]);
    if(tab[i] == tab[i - 1]){
      dist[i] = dist[i - 1];
      dist1[i] = dist1[i - 1];
      continue;
    }
    dist[i] = dist[i - 1] + b;
    dist1[i] = dist1[i - 1] + a;
  }  
  while(q--){ 
    int cur;
    cin >> cur;
    if(cur == 2){ 
      int a,b;
      cin >> a >> b;
      a = (a + x + n) % n;
      b = (b + x + n) % n;
      //a = tab[a]; b = tab[b];
      if(a > b) swap(a,b);
      if(tab[a] == tab[b]){
        cout << "0\n";
        x = 0;
        continue;
      }
      int t = dist[b] - dist[a], t1 = dist1[b] - dist1[a];
      bool ok = f(1, 0, m - 1, tab[a], tab[b]), ok1 = f(1, 0, m - 1, 0, tab[a]) or f(1, 0, m - 1, tab[b], n - 1); 
      x = 2e9;
      if(not ok){
        x = min(x, t);
      }
      if(not ok1){
        x = min(x, t1);
      }
      if(x == 2e9){
        x = -1;
      }
       //cout << "DIST " << a << " to " << b << ": " << t << ", " << t1 << " END\n";
      cout << x << endl;
       //cout << "\nTEST " << a << " " << b << " " << x << endl;
    }else{
      int a;
      cin >> a;
      a = (a + x) % m;
      add(a);
      // for(int i = 0; i < 5; i++){
      //   cout << tree[base + i] << " ";
      // }
      // cout << endl;
    }
  }
}
