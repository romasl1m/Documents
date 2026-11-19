#include <iostream>
#include <algorithm>
using namespace std;
int tab[7];
int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 7; i++){
            cin >> tab[i];
        }
        sort(tab, tab + 7);
        int res = 0;
        for(int i = 0; i < 6; i++){
            res -= tab[i];
        }
        res += tab[6];
        cout << res << "\n";
    }
}
