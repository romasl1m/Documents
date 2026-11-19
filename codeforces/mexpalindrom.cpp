#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i=(a); i<(n); i++)
#define cookie(t) while(t--)
int main(){
    raindrop
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> tab(n << 1);
        vector<int> pos0;
        droptop(0, n << 1){
            cin >> tab[i];
            if(tab[i] == 0){
                pos0.push_back(i);
            }
        }
        int res = 0;
        int centers[3] = {(pos0[0] << 1), (pos0[1] << 1), pos0[0] + pos0[1]};
        for(int c : centers){
            int l = c >> 1;
            int r = (c + 1) >> 1;
            while(l >= 0 and r < (n << 1) and tab[l] == tab[r]){
                l--;
                r++;
            }
            l++; 
            r--;
            vector<int> countin(n + 1, 0);
            for(int i=l; i<=r; i++){
                if(tab[i] < n){
                    countin[tab[i]]++;
                }
            }
            int mex = 0;
            while(mex < n and countin[mex] > 0){
                mex++;
            }
            res = max(res, mex);
        }
        cout << res << "\n";
    }
    return 0;
}
