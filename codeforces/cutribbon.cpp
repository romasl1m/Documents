#include <iostream>
using namespace std;
int dp[4001];
int main() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++) dp[i] = -1e9;
    for(int i = 0; i <= n; i++) {
        if(i + a <= n) dp[i + a] = max(dp[i + a], dp[i] + 1);
        if(i + b <= n) dp[i + b] = max(dp[i + b], dp[i] + 1);
        if(i + c <= n) dp[i + c] = max(dp[i + c], dp[i] + 1);
    }
    cout << dp[n];
}
