#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int xy = x + y;
        if(y < x){
            cout << "no\n";
            continue;
        }
        if(x == 0 and xy % 2 == 0){
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
        int cur = (x << 1) + ((x - y) % 2 + 2) % 2;
        for(int i = 2; i <= cur; i++){
            cout << i - 1 << " " << i << "\n";
        }
        for(int i = cur + 1; i <= xy; i++){
            cout << cur << " " << i << "\n";
        } 
    }
}
