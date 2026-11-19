#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
int tab[100'001];
vector<int> wec[100'001];
vector<int> common;
vector<long long> pref[100'001];
long long f(int a, int b){
    if(wec[a].size() > wec[b].size()){
      swap(a,b);
    }
    long long res = 0;
    vector<long long> pre(wec[b].size() + 1, 0);
    for(int i = 0; i < wec[b].size(); i++){
      pre[i + 1] = pre[i] + wec[b][i];
    }
    for(int i : wec[a]){
      int k = lower_bound(wec[b].begin(), wec[b].end(), i) - wec[b].begin();
      res += (long long)k * i - pre[k];
      res += (pre[wec[b].size()] - pre[k]) - (long long)((wec[b].size() - k) * i);
    }
    return res;
}
int main(){
    int z;
    cin >> z;
    while(z--){
        int n,m,q;
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
          wec[i].clear();
        }
        common.clear();
        int s = sqrt(n);
        for(int i = 1; i <= n; i++){
          cin >> tab[i];
          wec[tab[i]].push_back(i);
        }
        for(int i = 1; i <= m; i++){
            if(wec[i].size() >= s){
              common.push_back(i);
            } 
        }
        unordered_map<int,long long> dist[100'001];
        for(int i : common){
            long long total = wec[i].size();
            long long sum = 0;
            for(int j : wec[i]){
              sum += (long long)j;
            }
            long long powt = 0, sum2 = 0;
            for(int j = 1; j <= n; j++){
                if(tab[j] == i){
                  powt++;
                  sum2 += j; 
                }else{
                  long long l = powt, r = total - powt;
                  long long cur = l * j - sum2 + (sum - sum2) - r * j;
                  dist[i][tab[j]] += cur;
                }
            }
        }
        while(q--){
            int a,b;
            cin >> a >> b;
            if(wec[a].size() >= s and wec[b].size() >= s){
              cout << dist[a][b] << "\n";
            }else{
              cout << f(a,b) << "\n";
            }
        }
    }
}
