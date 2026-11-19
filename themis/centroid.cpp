#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> wec[100'001];
bool wiz[100'001];
int tab[100'001];
void dfs(int w){
    wiz[w] = true;
    for(int ss : wec[w]){
        if(wiz[ss]) continue;
        dfs(ss);
        tab[w] += tab[ss];
    }
    tab[w]++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        wec[b].push_back(a);
    }
    dfs(1);
    vector<int> res;
    int lim = n >> 1;
    for(int i = 1; i <= n; i++){
        int makssub = n - tab[i];
        for(int ss : wec[i]){
          if(tab[ss] < tab[i]) makssub = max(makssub, tab[ss]);
        }
        if(makssub <= lim){
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    for(int ss : res){
      cout << ss << " ";
    }
}
