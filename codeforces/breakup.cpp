#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a < b;
}

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);

struct s{
    int a,b,c;
};

vector<s> roads;
vector<pair<int,int>> wec[1001];

bool wiz[1001];
bool wizp[30001];
int tin[1001], low[1001], cur;
int tout[1'001];
int par[1001], paredge[1001];

long long best = (long long)2e18;
vector<int> ans;
bool findpath(int s, int t){
    droptop(1,1001){
        wiz[i] = false;
    }
    stack<int> st;
    st.push(s);
    wiz[s] = true;
    par[s] = -1;
    while(not st.empty()){
        int w = st.top();
        st.pop();
        for(auto [ss,id] : wec[w]){
            if(wiz[ss] or wizp[id]) continue;
            wiz[ss] = true;
            par[ss] = w;
            paredge[ss] = id;
            st.push(ss);
        }
    }
    return wiz[t];
}
void dfs(int w, int p = -1){
    wiz[w] = true;
    tin[w] = low[w] = ++cur;
    for(auto [ss,id] : wec[w]){
        if(wizp[id]) continue;
        if(id == p) continue;
        if(wiz[ss]){
            low[w] = min(low[w], tin[ss]);
        }else{
            par[ss] = w;
            dfs(ss,id);
            low[w] = min(low[w], low[ss]);
        }
    }
    tout[w] = cur;
}
bool check(int s, int t){
    droptop(1,1001){
        wiz[i] = false;
    }
    stack<int> st;
    st.push(s);
    wiz[s] = true;
    while(not st.empty()){
        int w = st.top();
        st.pop();
        for(auto [ss,id] : wec[w]){
            if(wiz[ss] or wizp[id]) continue;
            wiz[ss] = true;
            st.push(ss);
        }
    }
    return wiz[t];
}
int main(){
    raindrop
    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    droptop(0,m){
        int a,b,c;
        cin >> a >> b >> c;
        roads.push_back({a,b,c});
        wec[a].push_back({b,i});
        wec[b].push_back({a,i});
    }
    if(not findpath(s,t)){
        cout << "0\n0";
        return 0;
    }
    vector<int> path;
    int cur1 = t;
    while(cur1 != s){
        path.push_back(paredge[cur1]);
        cur1 = par[cur1];
    }
    for(int id1 : path){
        wizp[id1] = true;
        if(not check(s,t)){
            if(roads[id1].c < best){
                best = roads[id1].c;
                ans = {id1};
            }
        }else{
            droptop(1,n + 1){
                tout[i] = wiz[i] = tin[i] = low[i] = false;
            }
            cur = 0;
            droptop(1,n + 1){
                par[i] = -1;
            }
            dfs(s);
            for(int j = 0; j < m; j++){
                if(wizp[j]) continue;
                int w = roads[j].a;
                int ss = roads[j].b;
                if(not wiz[w] or not wiz[ss]) continue;
                if(par[w] == ss){
                    if(low[w] > tin[ss] and tin[w] <= tin[t] and tin[t] <= tout[w]){
                        long long cost = 1LL * roads[id1].c + roads[j].c;
                        if(cost < best){
                            best = cost;
                            ans = {id1,j};
                        }
                    }
                }

                if(par[ss] == w){
                    if(low[ss] > tin[w] and tin[ss] <= tin[t] and tin[t] <= tout[ss]){
                        long long cost = 1LL * roads[id1].c + roads[j].c;
                        if(cost < best){
                            best = cost;
                            ans = {id1,j};
                        }
                    }
                }
            }
        }
        wizp[id1] = false;
    }
    if(best == (long long)2e18){
        cout << -1 << "\n";
        return 0;
    }
    cout << best << "\n";
    cout << ans.size() << "\n";
    hotbox(ans);
    for(int x : ans) cout << x + 1 << " ";
    cout << '\n';
}
