#include <iostream>
#include <vector>
using namespace std;
int N,M;
void dfs(int n, int m, const vector<vector<char>> &wec, vector<vector<bool>> &wiz){
    if(n > N or m > M or n < 1 or m < 1 or wiz[n][m] or wec[n][m] == '#') return;
    wiz[n][m] = true;
    
    dfs(n - 1,m,wec,wiz);
    dfs(n,m + 1,wec,wiz);
    dfs(n,m - 1,wec,wiz);
    dfs(n + 1,m,wec,wiz);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        N = n; M = m;
        vector<vector<char>> wec(n + 2, vector<char> (m + 2));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> wec[i][j];
            }
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(wec[i][j] == 'B'){
                    if(wec[i][j - 1] == 'G'){
                        ok = false;
                        i = n;
                        break;
                    }
                    if(wec[i][j - 1] == '.') wec[i][j - 1] = '#';
                    if(wec[i - 1][j] == 'G'){
                        ok = false;
                        i = n;
                        break;
                    }
                    if(wec[i - 1][j] == '.') wec[i - 1][j] = '#';
                    if(wec[i + 1][j] == 'G'){
                        ok =  false;
                        i = n;
                        break;
                    }
                    if(wec[i + 1][j] == '.')wec[i + 1][j] = '#';
                    if(wec[i][j + 1] == 'G'){
                        ok = false;
                        i = n;
                        break;
                    }
                    if(wec[i][j + 1] == '.') wec[i][j + 1] = '#';
                }
            }
        }
        if(wec[n][m] == 'B' or not ok){
            cout << "No\n";
            continue;
        }
        vector<vector<bool>> wiz(n + 1, vector<bool> (m + 1));
        dfs(n,m, wec, wiz);
        ok = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(wec[i][j] == 'G' and not wiz[i][j]){
                    ok = false;
                    i = n;
                    break;
                }
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
