#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b){
    if(a == 0 or b == 0) return 0;
    return (a / gcd(a, b)) * b;
}
void f(){
    int n;
    cin >> n;
    vector<int> tab(n);
    for (int i = 0; i < n; i++) cin >> tab[i];
    int b;
    for (int i = 0; i < n; i++) cin >> b;
    if (n < 2) {
        cout << 0 << "\n";
        return;
    }
    vector<ll> g(n - 1);
    for(int i = 0; i < n - 1; i++){
        g[i] = gcd(tab[i], tab[i + 1]);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        ll cur;
        if(i == 0){
            cur = g[0];
        }else if(i == n - 1){
            cur = g[n - 2];
        }else{
            cur = lcm(g[i - 1], g[i]);
        }
        if(cur < tab[i]){
            res++;
        }
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}

