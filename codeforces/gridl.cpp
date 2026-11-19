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
        int p,q;
        cin >> p >> q;
        int cur = (p << 1) + (q << 2) + 1;
        bool ok = false;
        for(int i = 1; (long long)i * i <= cur; i += 2){
            if(cur % i != 0) continue;
            int j = cur / i;
            int n = (i - 1) >> 1, m = (j - 1) >> 1;
            if(q <= m * (n + 1) and q <= n * (m + 1)){
                ok = true;
                cout << n << " " << m << "\n";
                break;
            }
        }
        if(not ok) cout << "-1\n";
    }
}
