#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct s{
  int w,ss,c;
};
// vector<pair<int,int>> wec[200'001];
vector<s> roads;
int tab[200'001];
// bool wiz[200'001];
int tab2[200'001];
const long long mod = 1e9 + 7;
bool comp(s a, s b){
  return a.c < b.c;
}
int findf(int w){
  if(tab[w] == w) return w; 
  return tab[w] = findf(tab[w]);
}
void unia(int a, int b){
  a = findf(a); b = findf(b);
  if(a == b) return;
  if(tab2[a] < tab2[b]) swap(a,b);
  tab[b] = a;
  if(tab2[a] == tab2[b]) tab2[a]++;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  roads.resize(m);
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    // wec[a].push_back({b,c});
    // wec[b].push_back({a,c});
    roads[i] = {a,b,c};
  }
  sort(roads.begin(), roads.end(), comp);
  long long res = 1;
  for(int i = 1; i <= n; i++){
    tab[i] = i;
  }
  for(int i = 0; i < m; i++){
    int j = i;
    while(j < m and roads[j].c == roads[i].c) j++;
    int fw = findf(roads[i].w);
    int fss = findf(roads[i].ss);
    if(j - i == 2){
      if(i + 1 < m and roads[i].c == roads[i + 1].c){
        int fw = findf(roads[i].w);
        int fss = findf(roads[i].ss);
        int fw2 = findf(roads[i + 1].w);
        int fss2 = findf(roads[i + 1].ss);
        bool ok1 = (fss != fw);
        bool ok = (fss2 != fw2);
        if(ok and ok1){
            if((fss == fss2 and fw == fw2) or (fss == fw2 and fw == fss2)){
              res = (res << 1) % mod;
            }
        }
      }
    }
    for(int k = i; k < j; k++){
      if(findf(roads[k].w) != findf(roads[k].ss)){
        unia(roads[k].ss, roads[k].w);
      }
    }
    i = j - 1;
  }
  cout << res;
}
