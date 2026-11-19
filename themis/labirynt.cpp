#include <iostream>
#include <queue>
using namespace std;
char tab[502][502];
bool wiz[502][502];
int n,m,k;
int cur = 0;
int xs[4] = {1,-1,0,0};
int ys[4] = {0,0,1,-1};
queue<pair<int,int>> q;
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int x1,y1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tab[i][j];
            if(tab[i][j] == '.'){
                cur++;
                x1 = i; y1 = j;    
            }
        }
    }
    wiz[x1][y1] = true;
    q.push({x1,y1});
    cur -= k;
    // cout << cur << endl;
    // cout << (n * m) - (cur - k) << endl;
    int wizt = 1;
    while(not q.empty()){
        if(wizt >= cur) break;
        // cout << wizt << endl;
        auto [x,y] = q.front();
        q.pop();
        if(wizt >= cur) break;
        for(int i = 0; i < 4; i++){
            x1 = x + xs[i];
            y1 = y + ys[i];
            if(x1 < 1 or x1 > n or y1 < 1 or y1 > m) continue;
            if(not wiz[x1][y1] and tab[x1][y1] == '.'){
                wizt++;
                wiz[x1][y1] = true;
                q.push({x1,y1});
            }
            if(wizt >= cur) break;
        }
        if(wizt >= cur) break;
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m ;j++){
    //         cout << wiz[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(tab[i][j] == '.' and !wiz[i][j]) tab[i][j] = 'X';
            cout << tab[i][j];
        }
        cout << "\n";
    }
}
