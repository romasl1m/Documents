#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);

vector<pair<int,int>> wec[400'001];
pair<pair<int,int>,bool> roads[400'001];
int low[400'001];
int pre[400'001];
bool wiz[400'001];
bool dir[400'001];
int cur = 0;

void dfs(int w, int p = -1){
    wiz[w] = true;
    low[w] = pre[w] = cur++;
    for(auto&[ss, ok] : wec[w]){
        if(ok == p) continue;
        if(wiz[ss]){
           low[w] = min(low[w], pre[ss]); 
           continue;
        }
        dfs(ss,ok);
        low[w] = min(low[w], low[ss]);

        if(low[ss] > pre[w]){
            roads[ok].second = true;
        }
    }
}

int siz(int w){
    int res = 1;
    wiz[w] = true;
    for(auto[ss,ok] : wec[w]){
        if(roads[ok].second or wiz[ss]){
            continue;
        }
        res += siz(ss);
    }
    return res;
}

bool wizr[400'001];
void last(int w){
    wiz[w] = true;
    for(auto &[ss,id] : wec[w]){
        if(wizr[id]) continue;
        wizr[id] = true;
        if(roads[id].first.first == w){
            dir[id] = false;
        }else{
            dir[id] = true;
        }
        if(wiz[ss]) continue;
        last(ss);
    }
}
int main(){
    raindrop;
    int n,m;
    cin >> n >> m;
    droptop(0,m){
        int a,b;
        cin >> a >> b;
        wec[a].push_back({b,i});
        wec[b].push_back({a,i});
        roads[i] = {{a,b}, false};
    }

    dfs(1);
    
    droptop(1,n + 1){
        wiz[i] = false;
    }
    pair<int,int> maks = {0,0};
    droptop(1,n + 1){
        if(wiz[i]) continue;
        int cur = siz(i);
        if(cur > maks.first){
            maks = {cur,i};
        }
    }
    cout << maks.first << "\n";

    droptop(1, n + 1){
        wiz[i] = false;
    }
    last(maks.second);

    droptop(0,m){
        if(dir[i]){
            cout << roads[i].first.first << " " << roads[i].first.second << "\n";
        }else{
            cout << roads[i].first.second << " " << roads[i].first.first << "\n";
        }
    }
}
