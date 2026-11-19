#include <iostream>
using namespace std;
int tab[20];
int main(){
    int t;
    cin >> t;
    int cur = 11;
    for(int i = 2; i <= 9; i++){
        tab[i] = cur;
        cur *= 10;
        cur++;
    }
    while(t--){
        int n;
        cin >> n;
        for(int i = 9; i > 0; i--){
            if(n < tab[i]) continue;
            n %= tab[i];
        }
        if(n == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
