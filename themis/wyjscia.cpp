#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
vector<pair<int,long long>> wec[1'000'001];
long long tab[1'000'001];
bool esc[1'000'001];
void dfs(int w, int p){
    for(auto [ss,c] : wec[w]){
        if(ss == p) continue;
        dfs(ss,w);
    }
    if(wec[w].size() == 1) return;
    bool ok = true;
    for(auto [ss,c] : wec[w]){
        if(esc[ss]){
            ok = false;
            break;
        } 
    }
    if(ok) esc[w] = true;
}
int main(){
    raindrop;
    int n;
    cin >> n;
    droptop(1,n + 1){
        cin >> tab[i];
    }
    bool ok = true;
    droptop(1,n){
        int a,b; long long c;
        cin >> a >> b >> c; 
        if(a > 1 or c > 1) ok = false;
        wec[a].push_back({b,c});
        wec[b].push_back({a,c});
    }
    if(ok) dfs(1,0);
    else{
    
    }
    int res = 0;
    droptop(1,n + 1){
        if(esc[i]){
            res++;
        }
    }
    cout << res << "\n";
}
