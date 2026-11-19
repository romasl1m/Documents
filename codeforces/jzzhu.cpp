#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
vector<pair<int,long long>> wec[100'001];
vector<int> wek[100'001];
pair<int,long long> tab[100'001];
long long dist[100'001];
int dup[100'001];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    cookie(m){
        int a,b; long long c;
        cin >> a >> b >> c;
        wec[a].push_back({b,c});
        wec[b].push_back({a,c});
    }
    
    droptop(2,n + 1){
        dist[i] = 1e18;
    } 
    droptop(0,k){
        int a; long long b;
        cin >> a >> b;
        tab[i] = {a,b};
        if(dist[a] > b){
            dist[a] = b;
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    droptop(1,n + 1){
        if(dist[i] == 1e18) continue;
        q.push({dist[i], i});
    }
    while(not q.empty()){
        auto [cur,w] = q.top();
        q.pop();
        if(cur > dist[w]) continue;
        for(auto [ss,war] : wec[w]){
            if(dist[ss] > dist[w] + war){
                dist[ss] = dist[w] + war;
                q.push({dist[ss], ss});
            }
        }
    }
    droptop(1, n + 1){
        for(auto [ss,cur] : wec[i]){
            if(dist[ss] == dist[i] + cur){
                dup[ss]++;
            }
        }
    }
    int res = 0;
    droptop(0,k){
        auto [w,cur] = tab[i];
        if(dist[w] < cur) res++;
        else{
            if(dup[w] > 0) res++;
            else dup[w]++;
        }
    }
    cout << res << "\n";
}
