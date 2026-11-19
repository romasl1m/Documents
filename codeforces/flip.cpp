#include <iostream>
#include <vector>
using namespace std;
int a[200'001];
int tab[200'001];
int f(int n, int k) {
    int cel = a[tab[0] - 1];
    int res = 0;
    int l = 0, mid = 0, r = 0;
    for(int i = 0; i < tab[0] - 1; i++){
        if(a[i] != cel) l++;
    } 
    for(int i = tab[0]; i < tab[k - 1] - 1; i++){
        if(a[i] != cel) mid++;
    }
    for(int i = tab[k - 1]; i < n; i++){
        if(a[i] != cel) r++;
    }
    return max(l,max(mid,r));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < k; i++){
            cin >> tab[i];
        }
        cout << f(n,k) << "\n";
    }
}
