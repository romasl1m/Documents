#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tab(n);
        for(int i = 0; i < n; i++){
            cin >> tab[i];
        }
        if(n < 3){
            for(int i = 0; i < n; i++) cout << n << " ";
        }else{
            for(int i = 0; i < n; i++) cout << 2 << " ";
        } 
        cout << "\n";
    }
}
