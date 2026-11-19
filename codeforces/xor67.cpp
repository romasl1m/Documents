#include <iostream>
#include <vector>
using namespace std;
int tab[30 * 3105][2];
int res = 0;
void ins(int x){
    int w = 0;
    for(int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        if(tab[w][bit] == -1){
            res++;
            tab[w][bit] = res;
            tab[res][0] = tab[res][1] = -1;
        }
        w = tab[w][bit];
    }
}
int f(int x){
    int w = 0;
    int cur = 0;
    for(int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        int opposite = 1 - bit;
        if(tab[w][opposite] != -1){
            cur |= (1 << i);
            w = tab[w][opposite];
        }else{
            w = tab[w][bit];
        }
    }
    return cur;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> wec(n);
        for(int i = 0; i < n; i++){
            cin >> wec[i];
        }
        res = 0;
        tab[0][0] = tab[0][1] = -1;
        int wyn = 0;
        ins(wec[0]);
        for(int i = 1; i < n; i++){
            wyn = max(wyn, f(wec[i]));
            ins(wec[i]);
        }
        cout << wyn << "\n";
    }
}
