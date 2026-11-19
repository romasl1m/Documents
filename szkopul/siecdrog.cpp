#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<pair<int, int>> wec[201];
int dist[201][201];
bool wiz[201][201];
int tab[201][201];
void dickstra(int w) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, w});
    while (not q.empty()) {
        auto cur = q.top();
        q.pop();
        for (auto ss : wec[cur.second]) {
            if (dist[ss.first][cur.second] > cur.first + ss.second) {
                dist[ss.first][cur.second] = dist[cur.second][ss.first] = cur.first + ss.second;
                q.push({dist[ss.first][cur.second], ss.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            wec[i].push_back({j, x});
            wec[j].push_back({i, x});
            tab[i][j] = x;
            tab[j][i] = x;
        }
    }
    // for(int i = 1; i <= n; i++){
    //   for(int j = 1; j <= n; j++){
    //     dist[i][j] = 1e9;
    //   }
    // }
    // set<pair<int,int>> s;
    // for(int i = 1; i <= n; i++){
    //     dickstra(i);
    //     dist[i][i] = 0;
    //     for(int j = 1; j < i; j++){
    //       if(dist[i][j] == tab[i][j]){
    //         s.insert({min(i,j), max(i,j)});
    //       }
    //     }
    //     for(int j = i + 1; j <= n; j++){
    //       if(dist[i][j] = tab[i][j]){
    //         s.insert({min(i,j), max(i,j)});
    //       }
    //     }
    // }
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            int fromi2j = tab[i][j];
            bool ok = true;
            for (int k = 1; k <= n; k++) {
                if (i == k or j == k)
                    continue;
                if (tab[i][k] + tab[k][j] == tab[i][j]) {
                    // cout << dist[i][k] << " " << dist[]
                    // cout << i << j << k << endl;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                s.insert({min(i, j), max(i, j)});
            }
        }
    }
    // cout << s.size() << endl;
    for (auto ss : s) {
        cout << ss.first << " " << ss.second << "\n";
    }
    return 0;
}
