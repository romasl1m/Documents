#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> wec[500'001];
vector<int> rew[500'001];
int scc[500'001];
int mint[500'001];
int pos[50'001];
bool wrong[500'001];
bool wrong0[500'001];
vector<int> topo;
void dfs(int w){
    for(int ss : wec[w]){
        if(scc[w] == scc[ss]) continue;
        scc[ss] = scc[w];
        dfs(ss);
    }
    pos[w] = topo.size();
    topo.push_back(w);
}
void dfs0(int w){
    for(int ss : rew[w]){
        if(scc[w] == scc[ss]) continue;
        scc[ss] = scc[w];
        dfs0(ss);
    }
    pos[w] = topo.size();
    topo.push_back(w);
}
int main(){
    int n,m;
    cin >> n >> m;
    topo.reserve(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        rew[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        scc[i] = i;
    }
    for(int i = 1; i <= n; i++){
        if(scc[i] > 0) continue;
        dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for(int i = 1; i <= n; i++){
        int par = scc[i];
        mint[par] = 1e9;
        for(int ss : wec[i]){
            mint[par] = min(mint[par], scc[ss]);
        }        
    }
    for(int i = 1; i <= n; i++){
        if(mint[pos[scc[i]]] != topo[pos[scc[i] + 1]]) wrong[i] = true;
    }
    for(int i = 1; i <= n; i++){
        mint[i] = 0;
        scc[i] = i;
        pos[i] = -1;
    }
    topo.clear();
    for(int i = 1; i <= n; i++){
        if(scc[i] > 0) continue;
        dfs0(i);
    }
    reverse(topo.begin(), topo.end());
    for(int i = 1; i <= n; i++){
        int par = scc[i];
        mint[par] = 1e9;
        for(int ss : rew[i]){
            mint[par] = min(mint[par], scc[ss]);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     if(mint[scc[i]] != topo[scc[i] + 1]) wrong0[i] = true;
    // }
    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(wrong[i] or wrong0[i]) continue;
        res.push_back(i);
    }
    cout << res.size() << "\n";
    for(int i : res) cout << i << " ";
    return 0;
}
