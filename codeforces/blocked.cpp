#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a > b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> wec(n);
        for(int i = 0; i < n; i++){
            cin >> wec[i];
        }
        hotbox(wec);
        bool ok = true;
        for(int i = 0; i < n - 1; i++){
            if(wec[i] == wec[i + 1]){
                cout << "-1\n";
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i = 0; i < n; i++){
                cout << wec[i] << " ";
            }
            cout << "\n";
        }
    }
}

