/*
Now playing:
Linkin Park - Figure.09 [Meteora (Bonus Edition)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

vector<pair<int, int>> wec[10'001];
int tab[10'001][10];
int res[10];

bool checkf(int pos, int war, const int &n, const int &d) {
    vector<vector<int>> dist(n + 1, vector<int>(1 << pos, 2e9));
    queue<pair<int, int>> q;
    dist[1][0] = false, q.push({1, 0});

    while (not q.empty()) {
        auto [w, mask] = q.front();
        q.pop();

        if (w == n and mask == (1 << pos) - 1 and dist[w][mask] <= d)
            return true;

        for (const auto &[ss, num] : wec[w]) {
            int nxt = mask;
            droptop(i, 0, pos)
            {
                if (tab[num][i] >= (i == pos - 1 ? war : res[i]))
                    nxt |= (1 << i);
            }

            if (dist[w][mask] + 1 < dist[ss][nxt] and dist[w][mask] + 1 <= d)
                dist[ss][nxt] = dist[w][mask] + 1, q.push({ss, nxt});
        }
    }
    return false;
}

int f() {
    int n, m, d, k;
    cin >> n >> m >> d >> k;
    int maks = 0;
    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb({b, i}), wec[b].pb({a, i});
        droptop(j, 0, k)
        {
            cin >> tab[i][j], maks = max(maks, tab[i][j]);
        }
    }

    droptop(i, 0, k)
    {
        int l = 0, r = maks;
        int cur = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (checkf(i + 1, mid, n, d))
                cur = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        if (cur == -1) {
            cout << "NIE\n";
            return 67;
        }
        res[i] = cur;
    }

    droptop(i, 0, k)
    {
        cout << res[i] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
