#include <iostream>
using namespace std;
string tab[2'000'071];
int trie[2'000'071][30];
int par[2'000'071];
int wrds[2'000'071];
bool endt[2'000'071];
int cur = 0;
int res = 2;
int wiz[2'000'071];
int tab0[2'000'071];
void add(const string& s, int idx){
  int w = 1;
  for(int i = 0; i < s.length(); i++){
    wrds[w]++;
    char c = s[i];
    if(trie[w][c - 'a'] == 0){
      trie[w][c - 'a'] = res;
      par[res] = w;
      w = res;
      res++;
    }else{
      w = trie[w][c - 'a'];
    }
    if(i == s.size() - 1){
      wrds[w]++;
      endt[w] = true;
      tab0[idx] = w;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> tab[i]; 
    add(tab[i], i);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans++;
    int w = tab0[i]; 
    for(int j = 0; j < 30; j++){
      if(trie[w][j] == 0) continue;
      ans--;
    }
    while(true){
      wiz[w] = true;
      if(endt[par[w]] == true or par[w] == 1) break;
      else if(wrds[par[w]] > wrds[w]){
        int chill = 0;
        bool ok = false;
        for(int j = 0; j < 30; j++){
          if(trie[par[w]][j] == 0) continue;
          chill++;
          if(not wiz[trie[par[w]][j]]){
            ok = true;
            break;
          }
        }
        if(ok) break;
        else{
          w = par[w];
          ans -= chill - 1;
          continue;
        }
      }else if(wrds[par[w]] > wrds[w]) break;
      else{
        w = par[w];
        continue;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
