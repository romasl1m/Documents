/*
Now playing:
Lida - Новая рок звезда [Новая рок звезда]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int zap[1'000'001];
int dep[1'000'001];
int level[1'000'001];
int par[1'000'001];
int maksdep = 0;

bool frst[1'000'001];
int siz[1'000'001];
vector<int> wec[1'000'001];
int res[1'000'001];

int main() {
    raindrop;
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        droptop(i, 0, q)
        {
            cin >> zap[i];
        }

        dep[1] = level[1] = 1;
        droptop(i, 2, n + 1)
        {
            cin >> par[i];
            dep[i] = dep[par[i]] + 1, level[dep[i]]++;
            maksdep = max(dep[i], maksdep);
        }

        droptop(i, 1, n + 1)
        {
            siz[i] = 1;
            frst[i] = true;
            if (level[i] > 0) {
                wec[level[i]].pb(i);
            }
        }
        res[n] = maksdep;

        // droptop(i, 1, n + 1)
        // {
        //     if (level[i] > 0) {
        //         wec[level[i]].pb(i);
        //     }
        // }
        //
        for (int i = n - 1; i >= 1; i--) {
            res[i] = res[i + 1];

            for (int x : wec[i + 1]) {
                if (frst[x] and level[x] == i + 1) {
                    int przesuniecie = siz[x];
                    level[x] = i;
                    wec[i].pb(x);

                    while (przesuniecie > 0) {
                        int y = x + siz[x];
                        if (y > n) {
                            res[i] = max(res[i], x + (przesuniecie + i - 1) / i);
                        }
                        res[i] = max(res[i], y + siz[y] - 1);

                        if (siz[y] == 1 and level[y] + przesuniecie < i) {
                            level[y] += przesuniecie;
                            przesuniecie = 0;
                            wec[level[y]].pb(y);
                        } else {
                            przesuniecie -= (i - level[y]) * siz[y];
                            siz[x] += siz[y];
                            frst[y] = false;
                        }
                    }
                }
            }
        }

        droptop(i, 0, q)
        {
            cout << (zap[i] >= n ? maksdep : res[zap[i]]) << " ";
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
