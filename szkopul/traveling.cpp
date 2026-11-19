#include <iostream>
#include <cmath>
using namespace std;
pair<long long,long long> tab[100'001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k,a,b;
        cin >> n >> k >> a >> b;
        for(int i = 1; i <= n; i++){
            long long x,y;
            cin >> x >> y;
            tab[i] = {x, y};
        }
        if(a <= k and b <= k){
          cout << "0\n";
          continue;
        }
        long long xa = tab[a].first;
        long long ya = tab[a].second;
        long long xb = tab[b].first;
        long long yb = tab[b].second;
        long long direct = abs(xa - xb) + abs(ya - yb);
        long long dista = 4e9;
        long long distb = 4e9;
        for(int i = 1; i <= k; i++){
            dista = min(dista, abs(tab[i].first - xa) + abs(tab[i].second - ya));
            distb = min(distb, abs(tab[i].first - xb) + abs(tab[i].second - yb));
        }
        cout << min(direct, dista + distb) << "\n";
    }
}
