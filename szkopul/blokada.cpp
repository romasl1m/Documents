#include <iostream>
#include <vector>
using namespace std;
int n,m, cur = 0;
vector<int> wec[100'001];
int low[100'001];
int wiz[100'001];
bool wizb[100'001];
long long res[100'001];
int dfs(int w, int p){
    wizb[w] = true;
    int cwiz = 1, blocked = 0;
    low[w] = wiz[w] = cur++;
    res[w] = (n - 1) << 1;
    for(int ss : wec[w]){
        if(ss == p) continue;

        if(not wizb[ss]){
            int siz = dfs(ss, w);
            cwiz += siz;
            if(low[ss] >= wiz[w]){
                blocked += siz;
                res[w] += (long long)(n - 1 - siz) * siz;
            }else{
                low[w] = min(low[w], low[ss]);
            }
        }else{
            low[w] = min(low[w], wiz[ss]);   
        }
    }
    res[w] += (n - blocked - 1) * blocked;
    return cwiz;
}
int main(){
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        wiz[i] = -1;
        low[i] = -1;
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        wec[b].push_back(a);
    }
    dfs(1,-1);
    for(int i = 1; i <= n; i++){
        cout << res[i] << "\n";
    }
}
