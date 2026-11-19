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
        vector<int> tab(n + 1);
        droptop(0,n){
            cin >> tab[i];
        }
        long long ans=0;
        for(int i = 0; i < n - 1; i++){
            if(__gcd(tab[i],tab[i + 1]) == abs(tab[i] - tab[i + 1])) ans++;
        }
        cout << ans << "\n";
    }
}
