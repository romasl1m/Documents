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
        vector<int> wec(n);
        int s1 = 0, s0 = 0, s2 = 0;
        droptop(0,n){
            cin >> wec[i];
            if(wec[i] == 0) s0++;
            else if(wec[i] == 1) s1++;
            else s2++;
        }
        int res = 0;
        res += s0; 
        while(s2 > 0){
            if(s1 > 0){
                s1--;s2--;
                res++;
            }else{
                if(s2 >= 3){
                    s2 -= 3;
                    res++;
                }else{
                    break;
                }
            }
        }
        while(s1 >= 3){
            s1 -= 3;
            res++;
        }
        cout << res << "\n";
    }
}
