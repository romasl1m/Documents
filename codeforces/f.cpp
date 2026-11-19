#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f(vector<int> &a, int n, int k){
    int x = a[k];
    int l = 0, r = 0;
    for(int i = k - 1; i >= 1; i--){
        if(a[i] != x and (i == 1 or a[i - 1] == x)){
            l++;
        }
    }
    for(int i = k + 1; i <= n; i++){
        if(a[i] != x and (i == n or a[i + 1] == x)){
            r++;
        }
    }
    return max(l,r) << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int pos;
        cin >> pos;
        cout << f(a,n,pos) << "\n";
    }
    return 0;
}
