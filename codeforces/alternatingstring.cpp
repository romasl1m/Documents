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
        string  s;
        cin >> s;
        int bad = 0;
        int n = s.length();
        droptop(0, n - 1){
            if(s[i] == s[i + 1]) bad++;
        }
        if(bad <= 2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

