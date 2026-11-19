#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define cookie(t) while(t--)
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> wec(n);
        for(int i = 0; i < n; i++){
            cin >> wec[i];
        }
        int cur = 1, res = 0;
        for(int i = 1; i < n; i++){
            if(wec[i] == wec[i - 1]) cur++;
            else{
                res = max(res, cur);
                cur = 1;
            }
        }
        res = max(res, cur);
        if(res < m) cout << "yes\n";
        else cout << "no\n";
    }
}
