#include <iostream>
using namespace std;
int tab[200'001];
bool check(int mid, int cur, int n, int k){
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(not cur){
            res++;
            cur ^= 1;
        }else{
            if(tab[i] <= mid){
                res++;
                cur ^= 1;
            }
        }
    }
    return res >= k;
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> tab[i];
    }
    int l = 1, r = 1e9;
    while(l < r){
        int mid = (l + r) >> 1; 
        if(check(mid,0,n,k) or check(mid,1,n,k)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l;
}
