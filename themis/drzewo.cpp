#include <iostream>
#include <vector>
using namespace std;
void dfs(int w, int p, const vector<vector<int>>& wec, const vector<bool>& color, vector<pair<int,int>>& sum){
    for(int ss : wec[w]){
        if(ss == p) continue;
        dfs(ss,w,wec,color,sum);
        sum[w].first += sum[ss].first;
        sum[w].second += sum[ss].second;
    }
    if(color[w] == true){
        sum[w].first++;
    }else{
        sum[w].second++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> wec(n + 1);
        vector<bool> color(n + 1, false);
        vector<pair<int,int>> sum(n + 1, {0,0});
        for(int i = 2; i <= n; i++){
            int x;
            cin >> x;
            wec[x].push_back(i);
            wec[i].push_back(x);
        }
        for(int i = 1; i <= n; i++){
            char c;
            cin >> c;
            if(c == 'W'){
                color[i] = true;
                continue;
            }
        }
        dfs(1,0,wec,color,sum);
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(sum[i].first == sum[i].second) res++;
        }
        cout << res << "\n";
    }
}
