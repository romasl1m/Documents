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
struct s{
    int a1,b1,x1,y1; 
};
int main(){
    int n,r;
    cin >> n >> r;
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    vector<s> tab(n);
    droptop(0,n){
        int a1,b1,x1,y1;
        cin >> a1 >> b1 >> x1 >> y1;
        a1 -= a; b1 -= b;
        x1 -= x; y1 -= y;
        tab[i] = {a1,b1,x1,y1};
    }
    long long rs = (long long)r * r;

}
