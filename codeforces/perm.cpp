#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        if(n == 1){
            cout << "1 2 3\n"; 
            continue;
        }
        int cur = n + 1;
        for(int i = 1; i <= n; i++){
            cout << i << " " << cur << " " << cur + 1 << " ";
            cur += 2;
        } 
        cout << "\n";
    }
    return 0;
}
