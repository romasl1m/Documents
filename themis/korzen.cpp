#include <iostream>
#include <vector>
using namespace std;
void dfs(int w, int p, const vector<vector<int>> &wec, const vector<int> &par, vector<int> &mint, vector<int> &tab){
    mint[w] = 1e9;
    for(int ss : wec[w]){
        if(ss == p) continue;
        dfs(ss,w,wec,par,mint,tab);
        mint[w] = min(mint[w], mint[ss]);
    }
    if(wec[w].size() == 1){
        mint[w] = tab[w];
        return;
    }
    if(mint[w] > tab[w]){
        if(w == 1){
            return;
        }
        int mid = ((mint[w] + tab[w]) >> 1);
        // cout << "tab " << w << " changed to " << mid << endl;
        tab[w] = mid;
        mint[w] = mid;
    }
    
    // cout << "tab in " << w << " is " << mint[w] << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tab(n + 1);
        vector<vector<int>> wec(n + 1);
        vector<int> mint(n + 1);
        vector<int> par(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> tab[i];
        }
        for(int i = 2; i <= n; i++){
            int x;
            cin >> x;
            wec[x].push_back(i);
            wec[i].push_back(x);
        }
        dfs(1,0,wec,par,mint, tab);
        int cur = 1e9;
        for(int i = 2; i <= n; i++){
            // cout << mint[i] << " ";
            cur = min(cur,mint[i]);
        }
        // cout << endl;
        cout << tab[1] + cur << "\n";
    }
}
