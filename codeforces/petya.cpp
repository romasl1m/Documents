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
    string a,b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        a[i] = toupper(a[i]);
        b[i] = toupper(b[i]);
    }
    if(a == b) cout << 0;
    else if(a < b) cout << -1;
    else cout << 1;
    return 0;
}
