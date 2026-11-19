#include <iostream>
using namespace std;
int tab[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mint = 1e9;
        int maks = 0;
        for(int i = 0; i < n; i++){
            cin >> tab[i];
            if(tab[i] < mint){
                mint = tab[i];
            }
            if(tab[i] > maks){
                maks = tab[i];
            }
        }
        cout << ((maks - mint + 1) >> 1) << "\n";
    }
} 
