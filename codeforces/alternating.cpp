#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
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
        droptop(0,n - 1){
            if(i % 2 == 0){
                cout << -1 << " ";
            }else{
                cout << 3 << " ";
            }
        }
        if(n % 2 == 0){
            cout << 2 << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}
