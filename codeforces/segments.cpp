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
const long  long maks = 998244353;
long long f0(long long x){
    // return (1 + (x + 1)) >> 2;
    if(x == 0) return 1;
    return 1 + (x + 1) / 4;
}
long long f1(long long x){
    // return (x + 3) >> 2;
    return (x + 3) / 4;
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        long long n,x;
        cin >> n >> x;
        long long l0 = f0(x - 1) % maks;
        long long l1 = f1(x - 1) % maks;
        long long r0 = (f0(n) - f0(x - 1) + maks) % maks;
        long long r1 = (f1(n) - f1(x - 1) + maks) % maks;
        long long res = (l0 * r0) % maks;
        res = (res + (l1 * r1)) % maks;
        cout << res << "\n";
    }
}

