#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int tab[100'001];
vector<int> wec[100'001];
int tim[100'001];
int rtim[100'001];
int nxt[100'001];
int out[100'001];
vector<int> rew[100'001];
int main(){
    raindrop;
    int n;
    cin >> n;
    droptop(1,n + 1){
        int t,k;
        cin >> t >> k;
        nxt[i] = k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            wec[x].push_back(i);
            rew[i].push_back(x);
            out[x]++;

        }
        tab[i] = t;
    }
    queue<int> q;
    droptop(1, n + 1){
        if(nxt[i] == 0){
            q.push(i);
            tim[i] = tab[i];
        }
    }
    int res = 0, cur = 0;
    while(not q.empty()){
        int w = q.front();
        q.pop();
        cur++;
        res = max(res, tim[w]);
        for(int ss : wec[w]){
            tim[ss] = max(tim[ss], tim[w] + tab[ss]);
            nxt[ss]--;
            if(nxt[ss] == 0){
                q.push(ss);
            }
        }
    }
    if(cur < n){
        cout << "CYKL\n";
        return 0;
    }
    cout << res << "\n";
    int qu;
    cin >> qu;
    droptop(1,n + 1){
        if(out[i] == 0) q.push(i);
    }
    while(not q.empty()){
        int w = q.front();
        q.pop();
        for(int ss : rew[w]){
            rtim[ss] = max(rtim[ss], rtim[w] + tab[w]);
            out[ss]--;
            if(out[ss] == 0) q.push(ss);
        }
    }
    cookie(qu){
        int m,d;
        cin >> m >> d;
        if(d + tim[m] + rtim[m] > res){
            cout << "TAK\n";
        }else{
            cout << "NIE\n";
        }
    }
}
