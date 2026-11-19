#include <iostream>
#include <queue>
using namespace std;
int tab[1000][1000];
bool wiz[1000][1000];
int res[2] = {0,0};
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
// pair<bool,bool> check(int x1, int y1){
//     bool ok[2] = {false,false};
//     for(int i = 0; i < 8; i++){
//         int nx = x1 + dx[i];
//         int ny = y1 + dy[i];
//         if(nx < 0 or ny < 0 or nx >= 1000 or ny >= 1000) continue;
//         if(tab[nx][ny] > tab[x1][y1]){
//             ok[1] = true;
//         }else if(tab[nx][ny] < tab[x1][y1]){
//             ok[0] = true;
//         }
//     }
//     if(ok[0] and ok[1]){
//         return {false,false};
//     }else if(ok[0]){
//         return {true,false};
//     }else{
//         return {true,true};
//     }
// }
int n;
pair<bool,bool> bfs(int x1, int y1){
    wiz[x1][y1] = true;
    bool hg = false, lw = false;
    queue<pair<int,int>> q;
    q.push({x1,y1});
    while(not q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
            // if(x1 == 0 and y1 == 4){
            //     cout << "HERE " << tab[x][y] << " " << tab[nx][ny] << endl;
            // }
            if(tab[nx][ny] > tab[x][y]) hg = true;
            else if(tab[nx][ny] < tab[x][y]){
                lw = true;
                // cout << "low " << x1 << " " << y1 << " " << nx << " " << ny << endl;
            }
            if(wiz[nx][ny] or tab[nx][ny] != tab[x][y]) continue;
            wiz[nx][ny] = true;
            q.push({nx,ny});
        } 
    }
    if(hg and lw){
        return {false,false};
    }
    if(hg) return {true,true};
    if(lw) return {true,false};
    cout << 1 << " " << 1;
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tab[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(wiz[i][j]) continue;
            // cout << "deb " << i << " " << j << " ";
            auto cur = bfs(i,j);
            // cout << cur.first << " " << cur.second << endl;
            if(cur.first){
                res[cur.second]++;
            }
        }
    }
    cout << res[0] << " " << res[1];
}
