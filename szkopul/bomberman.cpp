/*
Now playing:
Juice WRLD - I'll Give It My All (Stargazing) [I'll Give It My All (Stargazing)]
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

int tab[1002][1002];
int dist[1002][1002];
int odl[1002][1002];

int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

int f() {
    int n;
    cin >> n;
    pair<int, int> start, endp;
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

    queue<pair<int, int>> q;
    q.push(start);
    while (not q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == 0 or cur.second == 0 or cur.first == n + 1 or cur.second == n + 1)
            continue;

        droptop(i, 0, 4)
        {
            pair<int, int> nxt = cur;
            nxt.first += dx[i], nxt.second += dy[i];
            if (tab[nxt.first][nxt.second] == 2 or tab[nxt.first][nxt.second] == 1)
                continue;
            if (dist[nxt.first][nxt.second] > dist[cur.first][cur.second] + 1)
                dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + 1, q.push(nxt);
        }
    }

    while (not q.empty())
        q.pop();
    q.push(endp);
    while (not q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        droptop(i, 0, 4)
        {
            pair<int, int> nxt = cur;
            nxt.first += dx[i], nxt.second += dy[i];
            if (tab[nxt.first][nxt.second] == 2 or tab[nxt.first][nxt.second] == 1)
                continue;
            if (odl[nxt.first][nxt.second] > odl[cur.first][cur.second] + 1)
                odl[nxt.first][nxt.second] = odl[cur.first][cur.second] + 1, q.push(nxt);
        }
    }

    // droptop(i, 1, n + 1)
    // {
    //     droptop(j, 1, n + 1)
    //     {
    //         cerr << dist[i][j] << " " << odl[i][j] << endl;
    //     }
    // }

    int res = dist[endp.first][endp.second];
    cerr << res << endl;
    droptop(i, 1, n + 1)
    {
        droptop(j, 1, n + 1)
        {
            if (tab[i][j] == 2)
                continue;

            int cheapest = 1e9, exp = 1e9, cheapestx, cheapesty, expx, expy;
            int curx = i, cury = j;
            while (curx <= n and tab[curx][cury] != 2) {
                cheapest = min(cheapest, dist[curx][cury]), exp = min(exp, odl[curx][cury]), curx++;
                if (cheapest == dist[curx][cury])
                    cheapestx = curx, cheapesty = cury;
                if (exp == odl[curx][cury])
                    expx = curx, expy = cury;
            }
            curx = i;
            while (curx > 0 and tab[curx][cury] != 2) {
                cheapest = min(cheapest, dist[curx][cury]), exp = min(exp, odl[curx][cury]), curx--;
                if (cheapest == dist[curx][cury])
                    cheapestx = curx, cheapesty = cury;
                if (exp == odl[curx][cury])
                    expx = curx, expy = cury;
            }
            curx = i;
            while (cury <= n and tab[curx][cury] != 2) {
                cheapest = min(cheapest, dist[curx][cury]), exp = min(exp, odl[curx][cury]), cury++;
                if (cheapest == dist[curx][cury])
                    cheapestx = curx, cheapesty = cury;
                if (exp == odl[curx][cury])
                    expx = curx, expy = cury;
            }
            cury = j;
            while (cury > 0 and tab[curx][cury] != 2) {
                cheapest = min(cheapest, dist[curx][cury]), exp = min(exp, odl[curx][cury]), cury--;
                if (cheapest == dist[curx][cury])
                    cheapestx = curx, cheapesty = cury;
                if (exp == odl[curx][cury])
                    expx = curx, expy = cury;
            }

            cerr << i << " " << j << " " << cheapest << " " << exp << endl;
            res = min(res, cheapest + exp + (abs(cheapestx - expx) + abs(cheapesty - expy)));
        }
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
