/*
Now playing:
Linkin Park - Blackout [A Thousand Suns]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
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

bool dp[6'001][6'001];
int tab[6'001];
bool wiz[6'001];

void f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        cin >> tab[i];
        tab[i]--;
    }

    droptop(i, 0, n + 1)
    {
        droptop(j, 0, n + 1)
        {
            dp[i][j] = false;
        }
    }

    droptop(i, 0, n)
    {

        int mincur = tab[i], maks = tab[i];

        droptop(j, i, n)
        {
            if (wiz[tab[j]])
                break;
            wiz[tab[j]] = true;

            mincur = min(mincur, tab[j]), maks = max(maks, tab[j]);

            if (maks - mincur == j - i)
                dp[mincur][maks] = true;
        }
        droptop(j, i, n)
        {
            wiz[tab[j]] = false;
        }
    }

    for (int res = n; res > 0; res--) {
        for (int i = 0; (res << 1) + i <= n; i++) {
            if (dp[i][i + res - 1] and dp[i + res][i + (res << 1) - 1]) {
                cout << res << "\n";
                return;
            }
        }
    }
    cout << "0\n";
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
