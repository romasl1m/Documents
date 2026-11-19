#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(n) for(int i = 0; i < n; i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end());
int main(){
    raindrop;
    int n;
    cin >> n;
    int a = 0,b = 0,c = 0;
    droptop(n){
        int x,y,z;
        cin >> x >> y >> z;
        a += x; b += y; c += z;
    }
    if(a == 0 and  b == 0 and c == 0){
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}

