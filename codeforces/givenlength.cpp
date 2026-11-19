#include <iostream>
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
    int n,m;
    cin >> n >> m;
    int m1 = m;
    string res = "", ans = "";
    if(9 * n < m or (n > 1 and m == 0)){
        // cout << "-1 - 1";
        cout << "-1 -1"; 
        return 0;
    }

    ans = to_string(((n - 1) * 9 > m ? 1 : m - (n - 1) * 9));
    res = to_string(min(m,9));
    m -= ans[0] - '0';
    m1 -= res[0] - '0';
    string last = "";
    droptop(1,n){
        int cur = min(m,9);
        last += (to_string(cur));
        m -= cur;
    }
    reverse(last.begin(), last.end());
    cout << ans << last << " ";
    droptop(1,n){
        int cur = min(m1,9);
        // res.push_back(cur);
        res += to_string(cur);
        m1 -= cur;
    }
    cout << res;
}
