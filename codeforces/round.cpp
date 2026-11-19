#include <iostream>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(n) for(int i = 0; i < n; i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end());
int main(){
    raindrop;
    int n,k;
    cin >> n >> k;
    int res = 0;
    vector<int> wec(n);
    droptop(n){
        int x;
        cin >> x;
        wec[i] = x;
    }
    int cur = wec[k - 1];
    droptop(n){
        if(wec[i] >= cur and wec[i] > 0){
            res++;
        }
    }
    cout << res;
    return 0;
}

