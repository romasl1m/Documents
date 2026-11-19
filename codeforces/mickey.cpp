#include <iostream>
#include <vector>
using namespace std;
int divn(int x){
    if(x == 0) return 1;
    if(x < 0) x = -x;
    int res = 0;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            res += 1;
            if(i * i != x) res++;
        }
    }
    return res % 676767677;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        // cout << "new test \n\n";
        int x,y;
        cin >> x >> y;
        int sum = x + y;
        vector<int> tab(sum + 1);
        for(int i = 1; i <= x; i++){
            tab[i] = 1;
        }
        for(int i = x + 1; i <= sum; i++){
            tab[i] = -1;
        }
        // vector<int> pref(sum + 1);
        // for(int i = 1; i <= sum; i++){
        //     pref[i] = pref[i - 1] + tab[i];
        // }
        // if(x == 0){
        //     cout << divn(y) << "\n";
        // }else if(y == 0){
        //     cout << divn(x) << "\n";
        // }else{
        //     int res = 1;
        //     int dif = (x - y);
        //     if(dif % 2 == 0 and dif != 0){
        //         dif >>= 1;
        //         for(int i = 1; i <= sum; i++){
        //             if(pref[i] == dif){
        //                 cout << 2 << "\n";
        //                 break;
        //             }
        //         }
        //     }else{
        //         cout << 1 << "\n";
        //     }
        // }
        cout << divn(x - y) << "\n";
        for(int i = 1; i <= sum; i++){
            cout << tab[i] << " ";
        }
        cout << "\n";
    }
}
