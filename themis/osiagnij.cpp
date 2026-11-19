#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int tab[32789];
bool wiz[32789];
vector<int> wec[32789];
int dist[32789];
queue<int> q;
void bfs(int st){
    q.push(st);
    while(not q.empty()){
        int w = q.front();
        q.pop();
        if(wiz[w]) continue;
        wiz[w] = true;
        // wec[w].push_back((w + 1) % 32768);
        // wec[w].push_back((w << 1) % 32768);
        wec[(w << 1) % 32768].push_back(w);
        wec[(w + 1) % 32768].push_back(w);
        // cout << (w << 1) % 32758 << " " << (w + 1) % 32768 << endl;
        q.push((w << 1) % 32768);
        q.push((w + 1) % 32768);
    }
}
void df(){
    queue<int> q;
    q.push(0);
    while(not q.empty()){
        int w = q.front();
        q.pop();
        for(int ss : wec[w]){
            if(dist[ss] > dist[w] + 1){
                dist[ss] = dist[w] + 1;
                q.push(ss);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tab[i];
        bfs(tab[i]);
    }
    for(int i = 1; i <= 32768; i++){
        dist[i] = 1e9;
    }
    dist[0] = 0;
    df();
    // for(int i = 0; i < 19; i++){
    //     cout << dist[i] << " ";
    // }
    for(int i = 0; i < n; i++){
        cout << dist[tab[i]] << " ";
    }
}
