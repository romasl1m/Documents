#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int dep[500'001];
int par[500'001];
bool comp(pair<pair<int,int>, int> a, pair<pair<int, int>,int> b){
    return dep[a.second] > dep[b.second];
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
vector<int> wec[500'001];
int pre[500'001];
int post[500'001];
int lca[500'001][20];
const int base = 500'000;
int tab[1'000'001];
int cur = 0;
int n,q;
int lift(int b, int level){
    int diff = dep[b] - level; 
    for(int i = 19; i >= 0; i--){
        if((diff >> i) & 1) b = lca[b][i];
    }
    return b;
}
int lazy[1'000'001];
void add(int w, int x){
    for(int i = w; i <= n; i += i & -i){
        tab[i] += x; 
    }
}
int sum(int w){
    int res = 0;
    for(int i = w; i > 0; i -= i & -i){
        res += tab[i];
    }
    return res;
}
int lcaf(int a, int b){
    if(dep[a] > dep[b]) swap(a,b);
    b = lift(b, dep[a]);
    if(a == b){
        return a;
    }
    for(int i = 19; i >= 0; i--){
        if(lca[a][i] == lca[b][i]) continue;
        a = lca[a][i]; b = lca[b][i];
    }
    if(lca[a][0] == 0) return 1;
    return lca[a][0];
}
void dfs(int w, int p = 0){
    stack<pair<int,int>> s;
    s.push({w,0});
    while(not s.empty()){
        int w = s.top().first;
        int p = s.top().second;
        if(pre[w] == 0){
            pre[w] = ++cur;
            dep[w] = dep[p] + 1;
            par[w] = p;
            lca[w][0] = p;
            for(int i = 1; i < 20; i++){
                lca[w][i] = lca[lca[w][i - 1]][i - 1];
            }
            for(int ss : wec[w]){
                if(ss == p) continue;
                s.push({ss, w});
            }
        }else{
            if(post[w] == 0) post[w] = cur;
            s.pop();
        }
    }
}
int main(){
    raindrop;
    cin >> n >> q;
    droptop(1,n){
        int a,b;
        cin >> a >> b;
        wec[a].push_back(b);
        wec[b].push_back(a);
    }
    dfs(1);
    vector<pair<pair<int,int>, int>> qs;
    while(q--){
        int a, b;
        cin >> a >> b;
        int w = lcaf(a,b);
        qs.push_back({{a,b},w});
    }
    priority_queue<int> res;
    hotbox(qs);
    for(auto [p,w] : qs){
        int a = p.first, b = p.second;
        int pw = par[w];
        int p1 = sum(pre[p.first]) - (pw == 0 ? 0 : sum(pre[pw]));
        int p2 = sum(pre[p.second]) - (pw == 0 ? 0 : sum(pre[pw]));
        if(p1 == 0 && p2 == 0){
            res.push(-w);
            add(pre[w], 1);
            add(post[w] + 1, -1);
        }
    }
    cout << res.size() << "\n";
    while(not res.empty()){
        cout << -res.top() << " ";
        res.pop();
    }
}

