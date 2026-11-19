/*
Now playing:
21 Savage - No Heart [Savage Mode]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

int tab[1002][1002];
int dist[1002][1002];
int odl[1002][1002];

int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

int n;
pair<int, int> start, endp;
int bfs(int a, int b) {
    droptop(i, 1, n + 1)
    {
        droptop(j, 1, n + 1)
        {
            dist[i][j] = 1e9;
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (not q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == 0 or cur.second == 0 or cur.first == n + 1 or cur.second == n + 1)
            continue;

        droptop(i, 0, 4)
        {
            pair<int, int> nxt = cur;
            nxt.first += dx[i], nxt.second += dy[i];
            nxt.first += dx[i], nxt.second += dy[i];
            if (tab[nxt.first][nxt.second] == 2 or tab[nxt.first][nxt.second] == 1)
                continue;
            int cell = tab[nxt.first][nxt.second];
            if (cell == 2)
                continue;
            if (cell == 1 and not(nxt.first == a and nxt.second == b))
                continue;

            if (dist[nxt.first][nxt.second] > dist[cur.first][cur.second] + 1) {
                dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + 1;
                q.push(nxt);
            }
        }
    }
}
int f() {
    cin >> n;
    droptop(i, 1, n + 1)
    {
        droptop(j, 1, n + 1)
        {
            dist[i][j] = odl[i][j] = 1e9;
            char c;
            cin >> c;
            if (c == '.')
                tab[i][j] = 0;
            else if (c == '#')
                tab[i][j] = 1;
            else if (c == 'X')
                tab[i][j] = 2;
            else if (c == 'P')
                start = {i, j}, dist[i][j] = 0;
            else
                endp = {i, j}, odl[i][j] = 0;
        }
    }

    if (n > 50) {
        cout << bfs(-1, -1);
        return 0;
    } else {
        int best = bfs(-1, -1);
        droptop(i, 1, n + 1)
        {
            droptop(j, 1, n + 1)
            {
                if (tab[i][j] == 1) {
                    best = min(best, bfs(i, j));
                }
            }
        }
        cout << best;
    }
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
