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
const int base = 300'001;
int tab[base << 1];
void add(int w){
    w >>= 1;
    while(w >= 1){
        tab[w] = tab[w << 1] + tab[w << 1 | 1];
        w >>= 1;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    droptop(0,n){
        cin >> tab[base + i];
        add(base + i);
    }
    cookie(m){
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1){

        }
    }
}
