/*
Now playing:
Linkin Park - Up From the Bottom [From Zero (Deluxe Edition)]
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
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> o(n, vector<int>(n));

        droptop(i, 0, m)
        {
            int o1, a, b;
            cin >> o1 >> a >> b;
            a--, b--;
            o[a][b] = o[b][a] = o1;
        }
        vector<int> pos, negh;
        droptop(i, 0, n)
        {
            if (o[i][i] == 1)
                pos.pb(i);
            else if (o[i][i] == 2)
                negh.pb(i);
        }
        bool ok = true;

        droptop(ii, 0, pos.size())
        {
            int i = pos[ii];
            droptop(jj, 0, pos.size())
            {
                int j = pos[jj];
                if (o[i][j] != 1)
                    ok = false;
            }
        }

        droptop(ii, 0, negh.size())
        {
            int i = negh[ii];
            droptop(jj, 0, negh.size())
            {
                int j = negh[jj];
                if (o[i][j] != 2)
                    ok = false;
            }
        }
        if (not ok) {
            cout << "NO\n";
            continue;
        }
        // ujemny
        // dodatni
        int w = n + 1, s = n;
        vector<vector<pair<int, int>>> wec(w);
        droptop(idx, 0, negh.size())
        {
            int j = negh[idx];
            wec[s].pb({j, 1});
        }

        droptop(ii, 0, pos.size())
        {
            int i = pos[ii];
            droptop(in, 0, negh.size())
            {
                int q = negh[in], war = o[i][q];
                if (war == 2) {
                    wec[i].pb({q, 1});
                } else if (war == 1) {
                    wec[q].pb({i, 0});
                } else {
                    ok = false;
                }
            }
        }

        if (not ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> dist(w, 0), in(w, 0), cnt(w, 0);
        queue<int> q;
        q.push(s);
        in[s] = 1, cnt[s]++;

        bool bad = false;
        while (not q.empty() and not bad) {
            int ww = q.front();
            q.pop();

            in[ww] = 0;
            for (auto [ss, warc] : wec[ww]) {
                if (dist[ss] < dist[ww] + warc) {
                    dist[ss] = dist[ww] + warc;
                    if (not in[ss]) {
                        q.push(ss);
                        in[ss] = 1;
                        cnt[ss]++;
                        if (cnt[ss] > w) {
                            bad = true;
                            break;
                        }
                    }
                }
            }
        }

        if (bad) {
            cout << "NO\n";
            continue;
        }
        droptop(i, 0, negh.size())
        {
            int idx = negh[i];
            if (dist[idx] < 1)
                ok = false;
        }
        if (not ok) {
            cout << "NO\n";
            continue;
        }
        vector<ll> res(n, 0);

        droptop(i, 0, n)
        {
            if (o[i][i] == 1) {
                res[i] = (ll)dist[i];
            } else {
                res[i] = -(ll)dist[i];
            }
        }

        droptop(i, 0, n)
        {
            droptop(j, i, n)
            {
                int cur = o[i][j];
                ll sum = res[i] + res[j];
                if (cur == 1) {
                    if (sum < 0)
                        ok = false;
                } else if (cur == 2) {
                    if (sum >= 0)
                        ok = false;
                } else {
                    ok = false;
                }
            }
        }
        if (not ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        droptop(i, 0, n)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
