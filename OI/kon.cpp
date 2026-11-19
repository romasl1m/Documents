#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> wec[500'001];
int dep[500'001];
bool wiz[500'001];
int par[500'001];
void dfs(int w, int p){
    for(int ss : wec[w]){
        if(ss == p) continue;
        dep[ss] = dep[w] + 1;
        par[ss] = w;
        dfs(ss,w);
    }
}
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return dep[a.second] < dep[b.second];
}
bool f(int a, int b){
    if(dep[a] > dep[b]) swap(a,b);
    while(dep[b] > dep[a]){
        if(wiz[b]){
            cout << 1 << "\n" << b;
            return true;
        }       
        wiz[b] = true;
        b = par[b];
    }
    while(b != a){
        if(wiz[a]){
            cout << 1 << "\n" << a;
            return true;
        }
        if(wiz[b]){
            cout << 1 << "\n" << b;
            return true;
        }
        wiz[a] = wiz[b] = true;
        a = par[a];
        b = par[b];
    }
    wiz[a] = true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        wec[b].push_back(a);
    }
    dfs(1,0);
    if(q <= 2){
        int ran[2];
        for(int i = 0; i < q; i++){
            int a,b;
            ran[i] = a;
            cin >> a >> b;
            if(f(a,b)) return 0;
        }
        cout << q << "\n";
        for(int j = 0; j < q; j++){
            // cout << "RES " << j << endl;
            cout << ran[j] << " ";
        }
        return 0;
    }
    vector<pair<int,int>> tab(q);
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        tab[i] = {a,b};
    }
    sort(tab.begin(), tab.end(), comp);
    vector<int> res;
    // res.reserve(n);
    int last = -1e9;
    for(int i = 0; i < q; i++){
        // cout << last << " ";
        if(last >= tab[i].first) continue;
        res.push_back(tab[i].second);
        last = tab[i].second;
        // cout << "TAKEB ";
    }
    cout << res.size() << "\n";
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}
