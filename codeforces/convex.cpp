#include <iostream>
#include <deque>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(n) for(int i = 0; i < n; i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end());

bool tab[50][50];
int ok[50][50][5];
int dirf(int x, int y){
    if(x == -1 and y == 0) return 1;
    if(x == 0 and y == -1) return 2;
    if(x == 1 and y == 0) return 3;
    return 4;
}
int minf(int x, int y){
    int res = 1e9;
    for(int i = 0; i < 5; i++){
        if(ok[x][y][i] == -1) continue;
        res = min(res,ok[x][y][i]);
    }
    if(res == 1e9) return -1;
    return res;
}
int n,m;
pair<int,int> dirs[4] = {{-1,0},{0,-1},{1,0},{0,1}};
void bfs(int sx, int sy){
    deque<tuple<int,int, int,int>> q;
    q.push_back({sx, sy, 0,0});
    ok[sx][sy][0] = 0;
    while(!q.empty()){
        auto [x,y,dir,c] = q.front();
        if(tab[x][y] == false){
            continue;
        }
        q.pop_front();
        if(c > ok[x][y][dir] && ok[x][y][dir] != -1) continue;
        for(auto [dx,dy] : dirs){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 or ny < 0 or nx >= n or ny >= m or not tab[nx][ny]) continue;
            if(not tab[nx][ny]) continue;
            int ndir = dirf(dx,dy);
            int cost = c + (dir != 0 and dir != ndir);
            if(cost < 2 and (ok[nx][ny][ndir] == -1 or ok[nx][ny][ndir] > cost)){
                ok[nx][ny][ndir] = cost;
                if(dir == ndir or dir == 0) q.push_front({nx, ny, ndir,cost});
                else q.push_back({nx, ny, ndir,cost});
            }
        }
    }
}
vector<pair<int,int>> list;
int main(){
    raindrop;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == 'W'){
                tab[i][j] = false;
            }else{
                tab[i][j] = true;
                list.push_back({i,j});
            }
        }
    } 
    for(int i = 0; i < list.size(); i++){
        auto [x,y] = list[i];
        for(int k = 0; k < n; k++){
            for(int l = 0; l < m; l++){
                for(int f = 0; f < 5; f++){
                    ok[k][l][f] = -1;
                }
            }
        }
        bfs(x,y);
        for(int j = 0; j < list.size(); j++){
            if(i == j) continue;
            int cur = minf(list[j].first, list[j].second);
            if(cur == -1 or cur > 2){
                cout << "NO\n";
                return 0;
            } 
        }
    }
    cout << "YES\n";
    return 0;
}

