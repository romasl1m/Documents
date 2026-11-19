#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool wiz[1000001];
vector<pair<int,int>> wec[1000001];
vector<int> wec2[1000001];
int dist[1000001];
int n;
void dijkstra() {
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
        wiz[i] = false;
    }
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int w = q.top().second;
        q.pop();
        if (wiz[w]) continue;
        wiz[w] = true;
        for (pair<int,int> ss : wec[w]) {
            if (!wiz[ss.first] and dist[ss.first] > dist[w] + ss.second) {
                dist[ss.first] = dist[w] + ss.second;
                q.push({-dist[ss.first], ss.first});
            }
        }
    }
}
long long mst() {
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
        wiz[i] = false;
    }
    dist[1] = 0;
    long long res = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int w = q.top().second;
        q.pop();
        wiz[w] = true;
        res += dist[w];
        for (pair<int, int> ss : wec[w]) {
            if (!wiz[ss.first] and dist[ss.first] > ss.second) {
                dist[ss.first] = ss.second;
                q.push({-dist[ss.first], ss.first});
            }
        }
    }
    return res;
}
vector<int> odw;
int scc[1000001];
vector<int> revwec[1000001];
bool wiz2[1000001];
void dfs(int w) {
    wiz[w] = true;
    for (int ss : wec2[w]) {
        if (!wiz[ss]) dfs(ss);
    }
    odw.push_back(w);
}
void dfs_rev(int w, int cur) {
    wiz2[w] = true;
    scc[w] = cur;
    for (int ss : revwec[w]) {
        if (!wiz2[ss]) dfs_rev(ss, cur);
    }
}
int sccf() {
    for (int i = 1; i <= n; i++) {
        if (!wiz[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        wiz2[i] = false;
    }
    int cur = 0;
    for (int i = odw.size() - 1; i >= 0; i--) {
        if (!wiz2[odw[i]]) {
            cur++;
            dfs_rev(odw[i], cur);
        }
    }
    int maksscc = 0;
    for (int i = 1; i <= n; i++) {
        maksscc = max(maksscc, scc[i]);
    }
    return maksscc;
}
int main() {
    cin >> n;
}