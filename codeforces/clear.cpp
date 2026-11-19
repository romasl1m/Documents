#include <iostream>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);

int dp[501][501];
string s;
int n;

int f(int l, int r){
    int &res = dp[l][r];
    if(res != -1) return res;
    if(l == r) return res = 1;
    if(l > r) return res = 0;
    res = f(l + 1, r) + 1;
    droptop(l + 1, r + 1){
        if(s[l] == s[i]) res = min(res, f(l + 1, i - 1) + f(i,r));
    }
    return res;
}
int main(){
    raindrop;
    cin >> n;
    cin >> s;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    cout << f(0, n - 1);
    return 0;
}
