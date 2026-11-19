#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> pos(n + 1);
        vector<bool> wiz(n + 1, false);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            pos[x] = i;
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x == -1) continue;
            if(wiz[x]){
                ok = false;
            }
            wiz[x] = true;
            if(i <= n - k or i > k){
                if(pos[x] != i) ok = false;
            }else{
                if(pos[x] <= n - k or pos[x] > k){
                    ok = false;
                }
            }

        }
        if(ok){
            cout << "yes\n";
            continue;
        }
        cout << "no\n";
    }
}
