#include <iostream>
using namespace std;
int tab[502][502];
int n,m;
void f(pair<int,int> w){
  bool ok = true;
  if(w.first - 1 > 0){
    if(tab[w.first - 1][w.second] == 0){
      cout << "? " << w.first - 1 << " " << w.second << "\n" << flush;
      cin >> tab[w.first - 1][w.second];
      cout << flush;
    }
    if(tab[w.first - 1][w.second] < tab[w.first][w.second]){
      ok = false;
      f({w.first - 1, w.second});
    }
  }

  if(w.first + 1 <= n){
    if(tab[w.first + 1][w.second] == 0){
      cout << "? " << w.first + 1 << " " << w.second << "\n" << flush;
      cin >> tab[w.first + 1][w.second];
      cout << flush;
    }
    if(tab[w.first + 1][w.second] < tab[w.first][w.second]){
      ok = false;
      f({w.first + 1, w.second});
    }
  }

  if(w.second + 1 <= m){
    if(tab[w.first][w.second + 1] == 0){
      cout << "? " << w.first << " " << w.second + 1 << "\n" << flush;
      cin >> tab[w.first][w.second + 1];
      cout << flush;
    }
    if(tab[w.first][w.second + 1] < tab[w.first][w.second]){
      ok = false;
      f({w.first, w.second + 1});
    }
  }

  if(w.second - 1 > 0){
    if(tab[w.first][w.second - 1] == 0){
      cout << "? " << w.first << " " << w.second - 1 << "\n" << flush;
      cin >> tab[w.first][w.second - 1];
      cout << flush;
    }
    if(tab[w.first][w.second - 1] < tab[w.first][w.second]){
      ok = false;
      f({w.first, w.second - 1});
    }
  }
  if(ok){
    cout << "! " << w.first << " " << w.second << "\n" << flush;
    exit(0);
  }
}
int main(){
  int t;
  cin >> t; cin >> n >> m; pair<int,int> w = {1,1};
    cout << "? " << w.first << " " << w.second << "\n" << flush;
    cin >> tab[1][1];
    cout << flush;
    f(w);
}
