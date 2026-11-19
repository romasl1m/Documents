#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, x, y, a, b;
        cin >> n >> x >> y >> a >> b;
        vector<pair<long long, long long>> pts(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> pts[i].second;
        }
        map<long long, vector<long long>> wec; 
        for (int i = 0; i < n; i++) wec[pts[i].first].push_back(pts[i].second);
        for (auto &[x, w] : wec) sort(w.begin(), w.end());
        long long dp0 = 0, dp1 = 0;
        long long px0 = x, py0 = y;
        long long px1 = x, py1 = y;
        bool first = true;
        for(auto &[xcur, w] : wec){
            long long cur0 = w.front();
            long long cur1 = w.back();
            if(first){
                dp0 = (xcur - x) + abs(y - cur1) + (cur1 - cur0);
                dp1 = (xcur - x) + abs(y - cur0) + (cur1 - cur0);
                first = false;
            }else{
                long long ndp0 = min(dp0 + (xcur - px0) + abs(py0 - cur1) + (cur1 - cur0), dp1 + (xcur - px1) + abs(py1 - cur1) + (cur1 - cur0));
                long long ndp1 = min(dp0 + (xcur - px0) + abs(py0 - cur0) + (cur1 - cur0),dp1 + (xcur - px1) + abs(py1 - cur0) + (cur1 - cur0));
                dp0 = ndp0;
                dp1 = ndp1;
            }
            px0 = px1 = xcur; py0 = cur0; py1 = cur1;
        }
        long long res = min(dp0 + (a - px0) + abs(b - py0),dp1 + (a - px1) + abs(b - py1));
        cout << res << "\n";
    }
}
