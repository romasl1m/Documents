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
        string s;
        cin >> s;
        int l = 0, r = 0;
        droptop(1,n - 1){
            if(s[i - 1] == '1' and s[i + 1] == '1') s[i] = '1';
        }
        // cout << "S " << s << endl;
        droptop(0,n){
            if(s[i] == '1') r++;
        } 
        droptop(1,n - 1){
            if(s[i - 1] == '1' and s[i + 1] == '1') s[i] = '0';
        }

        // cout << "S " << s << endl;
        droptop(1,n - 1){
            if(s[i - 1] == '1' and s[i + 1] == '1') s[i] = '0';
        }

        // cout << "S " << s << endl;
        droptop(0,n){
            if(s[i] == '1') l++;
        }
        cout << l << " " << r << "\n";
    }
}
