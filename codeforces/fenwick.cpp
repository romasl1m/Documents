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
const int maks = 1'000'001;
int tab[maks];
void upd(int b, int war = 1){
    while(b < maks){
        tab[b] += war; 
        b += (b & -b);
    }
}
void query(int x){
     
}
int kth(int x){
    int pos = 0;
    for(int i = (1 << 20); i > 0; i >>= 1){
        if(pos + i < maks and tab[pos + i] < x){
            x -= tab[pos + i];
            pos += i;
        }
    }
    return pos + 1;
}
int main(){
    raindrop;
    int n,q;
    cin >> n >> q;
    droptop(0,n){
        int x;
        cin >> x;
        upd(x);
    }
    cookie(q){
        int x;
        cin >> x;
        if(x < 0){
            int del = kth(-x);
            upd(del,-1);
        }else{
           upd(x); 
        }
    }
    droptop(1,maks){
        if(tab[i] == 0) continue;
        cout << i << "\n";
        return 0;
    }
    cout << 0;
    return 0;
}
