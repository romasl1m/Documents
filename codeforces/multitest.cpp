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
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> wec(n + 2);
        vector<int> dp(n + 2);
        vector<bool> multitest(n + 2, false);
        vector<int> next(n + 2);
        vector<int> dep(n + 2, 0);
        vector<int> sufdep(n + 2, 0);
        int cur = 0;
        droptop(1,n + 1){
            cin >> wec[i];
        }
        for(int i = n; i >= 1; i--){
            next[i] = i + wec[i] + 1;
            if(next[i] == n + 1 or (next[i] <= n and multitest[next[i]])){
                multitest[i] = true;
            }else{
                multitest[i] = false;
            }
            if(next[i] <= n + 1) dep[i] = dep[min(next[i], n + 1)] + 1;
            sufdep[i] = cur + 1; 
            if(next[i] <= n){
                sufdep[i] = max(sufdep[i], sufdep[next[i]] + 1);
            }
            if(multitest[i]){
                cur = max(cur,dep[i]);
            }
        } 
        string res = "";
        droptop(1,n){
            if(multitest[i + 1] and dep[i + 1] == wec[i]){
                res += "0 ";
            }else if(multitest[i + 1] or sufdep[i + 1] >= wec[i]){
                res += "1 ";
            }else{
                res += "2 ";
            }
        }
        cout << res << "\n";
    }
}

