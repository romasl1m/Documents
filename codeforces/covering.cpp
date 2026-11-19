#include <iostream>
using namespace std;
int nwd(int a, int b){
    while(b){
        a %= b;
        swap(a,b);
    } 
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    // int ts = t;
    while(t--){
        int n,m,a,b;
        cin >> n >> m >> a >> b;
       // if(a > n) swap(a,n);
        // if(b > m) swap(b,m);
        // cout << "\n\ntest " << ts - t - 1 << " " << nwd(n,a) << " " << nwd(m,b) << " " << nwd(n,m) << endl;
        int cur = nwd(n,m);
        if(nwd(n,a) == 1 and nwd(m,b) == 1 and cur <= 2){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}
