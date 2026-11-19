/*
Now playing:
Lil Peep - yesterday [crybaby]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

int tab[100'001];
vector<int> wec[100'001];
ll dp[1 << 9], nxt[1 << 9], res[100'001];

int f() {
    int n, m, k;
    cin >> n >> m >> k;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }

    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b);
    }

    cookie(w, n, 1)
    {
        int out = 0;
        for (int ss : wec[w]) {
            out |= (1 << (ss - w - 1));
        }

        droptop(mask, 0, (1 << 9))
        {
            if (not(mask & 1))
                dp[mask] = nxt[mask >> 1];
            else
                dp[mask] = tab[w] + nxt[(mask >> 1) | out];
        }
        res[w] = dp[1];

        droptop(mask, 0, (1 << 9))
        {
            nxt[mask] = dp[mask];
        }
    }

    droptop(i, 1, n + 1)
    {
        cout << res[i] << "\n";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
