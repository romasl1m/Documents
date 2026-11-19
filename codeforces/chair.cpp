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
        vector<int> wec(n + 1);
        vector<int> pos(n + 1);
        int res = 0;
        int cur = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            pos[x] = i;
        }
        for(int i = 1; i <= n + 1; i++){
            res = max(res, i - 1 - cur);
            if(i <= n and pos[i] < i) cur++;
        } 
        cout << res << "\n";
    }
}
