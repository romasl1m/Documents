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
char tab[100'001];
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        int l = -1,r = -1;
        droptop(0,n){
            char c;
            cin >> c;
            if(c == 'L'){
                l = i;
            }
            tab[i] = c;
        }
        droptop(0,n){
            if(tab[i] == 'R'){
                r = i;
                break;
            }
        }
        if(r < 0 or l < 0){
            cout << -1 << "\n";
            continue;
        }
        if(l > r){
            cout << "0\n";
            continue;
        }
        cout << r << "\n";
    }
}
