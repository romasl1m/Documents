#include <iostream>
#include <vector>
#include <map>
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
        map<int,int> mapa;
        int n,k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        droptop(0,n){
            cin >> a[i];
            int x = min(a[i] % k, (k - (a[i] % k)) % k);
            mapa[x]++;
        }
        droptop(0,n){
            cin >> b[i];
            int x = min(b[i] % k, (k - (b[i] % k)) % k);
            mapa[x]--;
        }
        bool ok = true;
        for(auto [w,ss] : mapa){
            if(ss != 0){
                cout << "no\n";
                ok = false;
                break;
            }
        }
        if(ok) cout << "yes\n";
    }
}

