/*
Now playing:
Metro Boomin - Niagara Falls (Foot or 2) [with Travis Scott and 21 Savage] [HEROES and VILLAINS]
*/
#include <iostream>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
vector<int> wec[5'001];
vector<vector<int>> zap;
vector<int> tab[5'001];
int dist[2][5'001];
bool res[1'000'001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n, m, k;
        cin >> n >> m >> k;
        zap.resize(k, vector<int>(3));
        droptop(0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            wec[b].pb(a);
        }
        droptop(0, k)
        {
            int a, b, d;
            cin >> a >> b >> d;
            zap[i] = {a, b, d};
        }
        droptop(0, k)
        {
            int a = zap[i][0], b = zap[i][1], c = zap[i][2];
            if (tab[a].empty()) {
                tab[b].pb(i);
            } else {
                tab[a].pb(i);
            }
        }
        droptop(1, n + 1)
        {
            for (int j = 0; j <= n; j++) {
                dist[0][j] = dist[1][j] = 2e9;
            }
            if (not tab[i].empty()) {
                int st[2], end[2], cur[2][5'001];
                st[0] = 0, end[0] = 1, st[1] = end[1] = 0;
                cur[0][0] = i;
                int k = 0, d = 1;
                while (st[k] < end[k]) {
                    int w = cur[k][st[k]++];
                    for (int ss : wec[w]) {
                        if (dist[1 - k][ss] == 2e9) {
                            dist[1 - k][ss] = d;
                            cur[1 - k][end[1 - k]++] = ss;
                            // cout << "CHANGED " << 1 - k << " " << ss << " " << dist[1 - k][ss] << endl;
                        }
                    }
                    if (st[k] == end[k]) {
                        d++;
                        k = 1 - k;
                    }
                }
            }

            for (int j = 0; j < tab[i].size(); j++) {
                int id = tab[i][j];
                int d = zap[id][2], w = zap[id][0];
                // cout << d << " " << w << " " << id << " " << i << endl;
                if (w == i) {
                    w = zap[id][1];
                }
                // cout << "DEB " << id << " " << dist[d % 2][w] << endl;
                res[id] = (dist[d % 2][w] <= d);
            }
        }
        droptop(0, k)
        {
            if (res[i]) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        }
    }
}
