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
        int l = 0,r = 0;
        droptop(0,n){
            char c;
            cin >> c;
            if(c == '(') l++;
            else r++;
        }
        if(r == l){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

