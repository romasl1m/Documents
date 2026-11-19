#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int maks = (n - 1) * n;
        vector<int> colors(n * n + 1);
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                int x;
                cin >> x;
                colors[x]++;
            }
        }
        bool ok = true;
        for(int i = 1; i <= n * n; i++){
            if(colors[i] > maks){
                cout << "NO\n";
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
    }
}
