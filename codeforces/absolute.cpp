#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<long long> tab2(n);
        long long res = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            tab[i] = x; 
        }
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            tab2[i] = x; 
        }
        long long  maks = 0;
        for(int i = 0; i < n; i++){
            maks = max(maks, min(tab[i], tab2[i]));
            res += max(tab[i], tab2[i]);
        }
        cout << res + maks << "\n";
    }
} 
