/*
Now playing:
PnB Rock - Nowadays [TrapStar Turnt PopStar]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
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
#define short int
#define int long long
mt19937_64 randf(1337);
int tab[1002];
vector<vector<ll>> mask;
signed main() {
    raindrop;

    int t = 1;

    cookie(t)
    {
        int n, m, k;
        cin >> n >> m >> k;
        mask.resize(n + 2, vector<ll>(m + 2));
        // vector<vector<short>> pos(n + 1);
        droptop(0, k)
        {
            short x, y, a, b;
            cin >> x >> y >> a >> b;
            ll cur = randf();
            mask[x + 1][y + 1] ^= cur, mask[a + 1][b + 1] ^= cur;
            // pos[x].pb(y);
            // pos[a].pb(b);
        }
        ll res = 0;
        vector<vector<ll>> pref(n + 2, vector<ll>(m + 2));

        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= m + 1; j++) {
                pref[i][j] = mask[i][j] ^ pref[i - 1][j] ^ pref[i][j - 1] ^ pref[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {

            // ll cur1 = 0;
            //
            for (int j = i + 1; j <= n + 1; j++) {
                ll cur = 0; // countin da empty flds
                for (int k = 0; k <= m + 1; k++) {
                    tab[k] = pref[j][k] ^ pref[i - 1][k];
                    if (k > 0 and tab[k] == tab[k - 1]) {
                        cur++; // empty
                    }
                }
                // for (int k = 0; k < pos[j].size(); k++) {
                //     tab[i] ^= pos[j][k];
                // }

                // for (int k = 1; k <= m; k++) {
                //     pref[k] = pref[k - 1] ^ tab[k - 1];
                // }

                // hotbox(tab, tab + m + 1);
                sort(tab, tab + m + 2);
                ll pary = 0;
                int num = 1;
                for (int k = 1; k <= 1 + m; k++) {
                    if (tab[k] == tab[k - 1]) {
                        num++;
                    } else {
                        pary += (1LL * num * (num - 1)) >> 1;
                        num = 1;
                    }
                    // int h = k;
                    //
                    // while (h <= m and pref[h] == pref[k]) {
                    //     h++;
                    // }
                    // ll dif = h - k;
                    // cur1 += (dif * (dif - 1)) >> 1;
                    // k = h;
                }
                pary += (1LL * num * (num - 1)) >> 1;
                res += pary - cur;
                // cur1 = max(cur, cur1);
            }
            // res = max(res, cur1);
        }
        cout << res;
    }
    return 0;
}
