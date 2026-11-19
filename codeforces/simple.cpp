#include <iostream>
#include <vector>
int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> wec(n);
        for(int i = 0; i < n; i++){
            wec[i] = n - i;
        }
        for(int i = 0; i < n; i++){
            cout << wec[i] << " ";
        }
        cout << "\n";
    }
}
