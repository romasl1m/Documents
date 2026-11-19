#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int cur;
vector<vector<int>> wec;
void dfs(int w, vector<int> &res){
    res[w] = cur--;
    for(int ss : wec[w]){
        dfs(ss,res);
    }
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        wec.clear();
        wec.resize(n + 2);
        vector<int> res(n + 2);
        vector<int> tab(n + 2);
        droptop(1,n + 1){
            cin >> tab[i];
            if(tab[i] == -1) tab[i] = i + 1;
            wec[tab[i]].push_back(i);
        }
        cur = n + 1;
        dfs(n + 1, res);
        stack<int> s;
        bool ok = true;
        for(int i = n; i > 0 and ok; i--){
            while(not s.empty() and res[s.top()] < res[i]){
                s.pop();
            }
            if((s.empty() and tab[i] != n + 1) or (not s.empty() and s.top() != tab[i])){
                cout << "-1\n", ok = false;
            }
            s.push(i);
        }
        if(not ok) continue;
        droptop(1,n + 1){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
