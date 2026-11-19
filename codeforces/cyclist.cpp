#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k,p,m;
        cin >> n >> k >> p >> m;
        vector<int> wec(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> wec[i];
        }
        int res = 0;
        if(p <= k){
            m -= p;
            wec.push_back(wec[p]);
            wec.erase(wec.begin() + p);
            res++;
            continue;
        }
        auto mn = min_element(wec.begin() + 1, wec.begin() + k + 1);
        int cur = *mn;
        wec.erase(mn);
        wec.push_back(cur);
        m -= cur;
        cout << res << "\n";
    }
}
