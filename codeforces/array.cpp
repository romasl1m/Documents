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
        vector<int> wec(n);
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            cin >> wec[i];
        }
        for(int i = 0; i < n; i++){
            int sml = 0, bg = 0;
            for(int j = i + 1; j < n; j++){
                if(wec[j] < wec[i]) sml++;
                if(wec[j] > wec[i]) bg++;
            }
            res[i] = max(sml, bg); 
        }
        for(int i = 0; i < n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
