/*
Now playing:

*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

vector<pair<int, int>> wec[200'001];
int dist[200'001];
int in[200'001];

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        droptop(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            wec[a].pb({b, c});
            in[b]++;
        }

        droptop(i, 2, n + 1)
        {
            dist[i] = 1e18;
        }
        queue<int> q;
        droptop(i, 1, n + 1)
        {
            if (in[i] == 0)
                q.push(i);
        }

        while (not q.empty()) {
            int w = q.front();
            q.pop();

            for (auto [ss, war] : wec[w]) {
                if (dist[w] != 1e18 and dist[w] + war < dist[ss]) {
                    dist[ss] = dist[w] + war;
                }
                in[ss]--;
                if (in[ss] == 0) {
                    q.push(ss);
                }
            }
        }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // q.push({0, 1});
        // while (not q.empty()) {
        //     auto [odl, w] = q.top();
        //     q.pop();
        //     if (odl > dist[w])
        //         continue;
        //     for (auto [ss, weight] : wec[w]) {
        //         if (dist[ss] > dist[w] + weight) {
        //             dist[ss] = dist[w] + weight;
        //             q.push({dist[ss], ss});
        //         }
        //     }
        // }

        droptop(i, 1, n + 1)
        {
            cout << (dist[i] == 1e18 ? -1 : dist[i]) << "\n";
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
