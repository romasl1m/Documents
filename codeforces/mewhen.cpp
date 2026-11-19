#include <iostream>
#include <vector>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    for(int i = 0; i < n; i++){
      cin >> b[i];
      if(a[i] > b[i]) swap(a[i], b[i]);
    }

    if(n == 1){
      cout << min(a.front(), b.front()) << "\n";
      continue;
    }
    long long res = 0;
    vector<long long> suf(n), pref(n);
    long long curmaks = 0;
    pref[0] = a[0];
    suf[n - 1] = a[n - 1];
    for(int i = 1; i < n; i++) pref[i] = max(pref[i - 1], a[i]);
    for(int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], a[i]);
    for(int i = 0; i < n; i++){
      curmaks = 0;
      if(i > 0 and curmaks < pref[i - 1]) curmaks = pref[i - 1];
      if(i < n - 1 and curmaks < suf[i + 1]) curmaks = pref[i + 1];
      res = max(res, min(b[i], curmaks));
    }
    long long maks1 = 0, maks2 = 0;
    for(int i = 0; i < n; i++){
      if(a[i] >= maks1){
        maks2 = maks1;
        maks1 = a[i];
      } else if(a[i] > maks2){
        maks2 = a[i];
      }
    }
    res = max(res, maks2);
    cout << res << "\n";
  }
}
