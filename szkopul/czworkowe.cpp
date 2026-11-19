/*
Now playing:

*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

bool tab[1 << 10 | 1][1 << 10 | 1];
bool wiz[1 << 10 | 1][1 << 10 | 1];
void read(const string &s, int &idx, int x1, int y1, int x2, int y2) {
    if (idx >= s.length())
        return;
    char type = s[idx++];
    if (type == '0') {
        droptop(i, x1, x2 + 1)
        {
            droptop(j, y1, y2 + 1)
            {
                tab[i][j] = false;
            }
        }
    } else if (type == '1') {
        droptop(i, x1, x2 + 1)
        {
            droptop(j, y1, y2 + 1)
            {
                tab[i][j] = true;
            }
        }
    } else {
        int midx = x1 + ((x2 - x1) >> 1),
            midy = y1 + ((y2 - y1) >> 1);

        read(s, idx, x1, y1, midx, midy),
            read(s, idx, x1, midy + 1, midx, y2),
            read(s, idx, midx + 1, y1, x2, midy),
            read(s, idx, midx + 1, midy + 1, x2, y2);
    }
}

int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int m;
int dfs(int x, int y) {
    int cnt = 1;
    wiz[x][y] = true;
    droptop(i, 0, 4)
    {
        int cx = x + dx[i], cy = y + dy[i];
        if (cx >= (1 << m) or cy >= (1 << m) or cx < 0 or cy < 0 or wiz[cx][cy] or not tab[cx][cy])
            continue;
        cnt += dfs(cx, cy);
    }
    return cnt;
}

int f() {
    string s;
    cin >> m >> s;
    int idx = 0;
    read(s, idx, 0, 0, (1 << m) - 1, (1 << m) - 1);

    int res = 0, maks = 0;
    droptop(i, 0, (1 << m))
    {
        droptop(j, 0, (1 << m))
        {
            if (not wiz[i][j] and tab[i][j])
                res++, maks = max(maks, dfs(i, j));
        }
    }
    cout << res << "\n"
         << maks;
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
