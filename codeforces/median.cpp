#include <iostream>
using namespace std;
int tab[200'001];
int tab1[200'001];
int n,k;
bool check(int mid){
    for(int i = 0; i < n; i++){
        if(tab[i] >= mid) tab1[i] = 1;
        else tab1[i] = -1;
    } 
    for(int i = 1; i < n; i++){
        tab1[i] += tab1[i - 1];
    } 
    int maks = tab1[k - 1], mn = 0;
    for(int i = k; i < n; i++){
        mn = min(mn, tab1[i - k]);
        maks = max(tab1[i] - mn, maks);
    }
    return maks > 0;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> tab[i];
    } 
    int l = 1, r = n + 1;
    while(l < r - 1){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
