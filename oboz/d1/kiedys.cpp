#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
unordered_set<long long> mapa;
int main(){
  long long qt,t;
  cin >> qt >> t;
  priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long, long long>>> q;
  while(qt--){
    int tcur; long long tim,num;
    cin >> tcur >> tim >> num;
    if(tcur == 2){
      mapa.erase(num);
    }
    // if(not q.empty()) cout << "QTP " << q.top().first << endl << flush;
    while(not q.empty() and q.top().first <= tim){
      if(mapa.count(q.top().second)){
        cout << "Jest akcept! " << q.top().second << flush;
        return 0;
      }
      q.pop();
    }
    cout << "Dalej czekamy :(\n" << flush;
    if(tcur == 1){
      mapa.insert(num);
      q.push({tim + t, num});
    } 
  }
}
