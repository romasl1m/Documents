/*
Now playing:
Linkin Park - BURN IT DOWN [LIVING THINGS]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define int long long
#define ll long long
vector<pair<int, int>> wec[100'001];
int dist[100'001];
int tab[100'001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int res = 1e18;
void f() {
    while (not q.empty()) {
        auto [cur, w] = q.top();
        if (cur != dist[w]) {
            q.pop();
            continue;
        }
        q.pop();
        for (auto [ss, odl] : wec[w]) {
            // if (dist[ss] == 0) {
            //     // cerr << "connection " << w << " " << ss << " " << dist[w] << " " << odl << endl;
            //     int total = dist[w] + odl;
            //     res = min(res, total);
            // }
            if (dist[ss] > dist[w] + odl) {
                dist[ss] = dist[w] + odl;
                tab[ss] = tab[w];
                q.push({dist[ss], ss});
            } else if (tab[ss] != tab[w] and dist[ss] != 1e18) {
                res = min(res, dist[ss] + dist[w] + odl);
            }
        }
    }
}

signed main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int u, n, m;
        cin >> u >> n >> m;
        droptop(1, n + 1)
        {
            dist[i] = 1e18;
        }
        droptop(0, u)
        {
            int x;
            cin >> x;
            if (dist[x] == 0) {
                cout << 0;
                return 0;
            }
            q.push({0, x});
            dist[x] = 0;
            tab[x] = x;
        }
        cookie(m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            wec[a].pb({b, c});
            wec[b].pb({a, c});
        }
        f();
        // cerr << "RES " << res << endl;
        cout << res * 3;
    }
}
