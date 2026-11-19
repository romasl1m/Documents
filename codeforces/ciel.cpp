#include <iostream>
#include <vector>
using namespace std;
vector<int> wec[100'001];
int sub[100'001];
char tab[100'001];
bool wiz[100'001];
int subtr(int w, int p){
    sub[w] = 1;
    for(int ss : wec[w]){
        if(ss == p or wiz[ss]) continue;
        sub[w] += subtr(ss,w);
    }
    return sub[w];
}
int centr(int w, int p, int siz){
    for(int ss : wec[w]){
        if(ss == p) continue;
        if(wiz[ss]) continue;
        if(sub[ss] > (siz >> 1)){
            return centr(ss,w,siz);
        }
    }
    return w;
}
void dfs(int w, int p, char cur){
    int siz = subtr(w,-1);
    int cent = centr(w,-1,siz);
    tab[cent] = cur;
    wiz[cent] = true;
    for(int ss : wec[cent]){
        if(ss == p or wiz[ss]) continue;
        dfs(ss,cent,cur + 1);
    }
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
    dfs(1,-1, 'A');
    for(int i = 1; i <= n; i++){
        cout << tab[i] << " ";
    }
}
