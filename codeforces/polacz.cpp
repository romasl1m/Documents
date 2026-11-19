#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<long long> tab;
struct s{
    int x,y; long long w;
};
bool comp(s& a, s& b){
    return a.w < b.w;
}
int par[100'001];
int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}
bool unio(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return false;
    par[b] = a;
    return true;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    tab.resize(n + 1);
    int mind = 1;
    for(int i = 1; i <= n; i++){
        cin >> tab[i];
        if(tab[i] < tab[mind]){
            mind = i;
        }
    }
    vector<s> wec;
    wec.resize(n + m);
    for(int i = 1; i <= n; i++){
        if(i == mind) continue;
        wec.push_back({mind,i,tab[mind] + tab[i]});
    }
    for(int i = 0; i < m; i++){
        cin >> wec[i].x >> wec[i].y >> wec[i].w;
    }
    sort(wec.begin(), wec.end(), comp);
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    long long res = 0;
    for(const s& x : wec){
        if(unio(x.x, x.y)){
            res += x.w;
        }
    }
    cout << res;
    return 0;
}
