/*
Now playing:
Платина - Веном [Sosa Muzik]
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

const int mod = 1'000'000'007;
vector<int> wec[1'000'001];
vector<int> rew[1'000'001]; // p od miejsca
int rdeg[1'000'001];
int wdeg[1'000'001];
bool rmtch[1'000'001];
bool wmtch[1'000'001];
int tab[1'000'001];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n + 1)
        {
            char c;
            cin >> c;
            if (c == 'T') {
                int x;
                cin >> x;
                wec[i].pb(x);
                rew[x].pb(i);
            } else {
                int a, b;
                cin >> a >> b;
                wec[i].pb(b), wec[i].pb(a);
                rew[a].pb(i), rew[b].pb(i);
            }
        }

        queue<pair<bool, int>> q; // false - zaw-miejsce else miejsce -zaw;
        droptop(i, 1, n + 1)
        {
            rdeg[i] = rew[i].size(), wdeg[i] = wec[i].size();
            if (not rdeg[i] or not wdeg[i]) {
                cout << "NIE\n0";
                return 0;
            }
            if (rdeg[i] == 1)
                q.push({true, i});
            if (wdeg[i] == 1)
                q.push({false, i});
        }

        while (not q.empty()) {
            auto [typ, idx] = q.front();
            q.pop();
            if (not typ) { // Zawodnik o stopniu 1
                if (wmtch[idx])
                    continue;
                int place = -1;
                for (int ss : wec[idx]) {
                    if (not rmtch[ss]) {
                        place = ss;
                        break;
                    }
                }

                if (place == -1) {
                    cout << "NIE\n0";
                    return 0;
                }

                wmtch[idx] = rmtch[place] = true;
                tab[idx] = place;

                for (int ss : rew[place]) {
                    if (wmtch[ss])
                        continue;
                    wdeg[ss]--;
                    if (not wdeg[ss]) {
                        cout << "NIE\n0";
                        return 0;
                    }
                    if (wdeg[ss] == 1) {
                        q.push({false, ss});
                    }
                }

                for (int ss : wec[idx]) {
                    if (rmtch[ss])
                        continue;
                    rdeg[ss]--;
                    if (not rdeg[ss]) {
                        cout << "NIE\n0";
                        return 0;
                    }
                    if (rdeg[ss] == 1) {
                        q.push({true, ss});
                    }
                }
            } else {
                if (rmtch[idx])
                    continue;

                int zaw = -1;
                for (int ss : rew[idx]) {
                    if (not wmtch[ss]) {
                        zaw = ss;
                        break;
                    }
                }

                if (zaw == -1) {
                    cout << "NIE\n0";
                    return 0;
                }

                wmtch[zaw] = rmtch[idx] = true;
                tab[zaw] = idx;

                for (int ss : wec[zaw]) {
                    if (rmtch[ss])
                        continue;
                    rdeg[ss]--;
                    if (not rdeg[ss]) {
                        cout << "NIE\n0";
                        return 0;
                    }
                    if (rdeg[ss] == 1) {
                        q.push({true, ss});
                    }
                }

                for (int ss : rew[idx]) {
                    if (wmtch[ss])
                        continue;
                    wdeg[ss]--;
                    if (not wdeg[ss]) {
                        cout << "NIE\n0";
                        return 0;
                    }
                    if (wdeg[ss] == 1) {
                        q.push({false, ss});
                    }
                }
            }
        }

        int cycles = 0;
        droptop(i, 1, n + 1)
        {
            if (not wmtch[i]) {
                cycles++;
                int cur = i;
                while (not wmtch[cur]) {
                    wmtch[cur] = true;
                    int place = -1;
                    for (int ss : wec[cur]) {
                        if (rmtch[ss])
                            continue;
                        place = ss;
                        break;
                    }
                    if (place == -1)
                        break;
                    rmtch[place] = true;
                    int nxt = -1;
                    for (int ss : rew[place]) {
                        if (wmtch[ss])
                            continue;
                        nxt = ss;
                        break;
                    }
                    if (nxt != -1) {
                        cur = nxt;
                    } else {
                        break;
                    }
                }
            }
        }
        if (cycles == 0) {
            cout << "TAK\n";
            droptop(i, 1, n + 1)
            {
                cout << tab[i] << "\n";
            }
            return 0;
        }
        int res = 1;
        droptop(i, 0, cycles)
        {
            res <<= 1;
            res %= mod;
        }

        cout << "NIE\n"
             << res;
        return 0;
    }
}
