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
        long long n,x,y,k;
        cin >> n >> x >> y >> k;
        long long d = llabs(x - y);
        d = min(d, n - d);
        long long res = (n <= 3) ? d : (d + k);
        cout << res << "\n";
    }
}
