#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
const long long mod = 676767677;
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        int one = -1;
        vector<int> wec(n);
        for(int i = 0; i < n; i++){
            cin >> wec[i];
        }
        // hotbox(wec);
        long long res = 0;
        long long minf = 1e18;
        // for(int i = 0; i < n - i - 1; i++){
        //     long long cur = wec[i] * wec[n - i - 1];
        //     if(cur == 1){
        //         minf = 1;
        //         continue;
        //     }
        //     res = (res + cur) % mod;
        //     minf = min(cur,minf);
        // }
        // if(n % 2 == 1){
        //     res = (res + (minf * (wec[(n >> 1) | 1] - 1))) % mod;
        // }
        // if(res == 0) res++;
        droptop(0,n){
            if(wec[i] > 1){
                res += wec[i];
                one = i;
            }
        }
        if(one == -1){
            cout << 1 << "\n";
            continue;
        }
        if(one < n - 1) res++;
        cout << res % mod << "\n";
    }
}

