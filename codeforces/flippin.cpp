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
        vector<long long> tab(n);
        for(int i = 0; i < n; i++){
            cin >> tab[i];
        }
        bool ok = false;
        vector<int> res;
        for(int i = n - 1; i >= 0; i--){
            long long cur = ok ? -tab[i] : tab[i];
            if(cur > 0){
                res.push_back(i + 1);
                ok = not ok;
            }

        }
        cout << res.size() << "\n";
        for(int i : res){
            cout << i << " ";
        }
        cout << "\n";
    }
}