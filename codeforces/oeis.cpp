#include <iostream>
#include <vector>
using namespace std;
vector<int> prime(int n){
    vector<int> ps;
    vector<bool> wiz(200000, true);
    for(int i = 2; ps.size() < n + 1; i++){
        if(wiz[i]){
            ps.push_back(i);
            for(int j = (i << 1); j < 200000; j += i){
                wiz[j] = false;
            }
        }
    }
    return ps;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;   
    vector<int> pierwsze = prime(10001);
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            long long cur = (long long) pierwsze[i] * pierwsze[i + 1];
            cout << cur << " ";
        }
        cout << "\n";
    }
    return 0;
}
