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
int f(int pos, int n){
    if(pos > n) return n + 1;
    if(pos == n) return 0;
    return -1;
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> wec(n);
        vector<int> dp(n);
        droptop(0,n){
            cin >> wec[i];
        }
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            int cur = f(i + wec[i] + 1, n);
            if(cur == -1) cur = dp[i + wec[i] + 1];
            dp[i] = min(dp[i + 1] + 1, cur);
        }
        cout << dp[0] << "\n";
    }
}

