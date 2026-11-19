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
vector<vector<char>> tab;
int main(){
    raindrop;
    int t;
    cin>>t;
    cookie(t){
        int n;
        cin>>n;
        tab.assign(2, vector<char>(n));
        droptop(0, n){
            cin>>tab[0][i];
        }
        droptop(0, n){
            cin>>tab[1][i];
        }
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        droptop(1, n + 1){
            int cur;
            if(tab[0][i - 1] == tab[1][i - 1]){
                cur = 0;
            }else{
                cur = 1;
            }
            dp[i] = min(dp[i], dp[i - 1] + cur);
            if(i >= 2){
                int curh = 0;
                if(tab[0][i - 2] != tab[0][i - 1]){
                    curh++;
                }
                if(tab[1][i - 2] != tab[1][i - 1]){
                    curh++;
                }
                dp[i] = min(dp[i], dp[i - 2] + curh);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
