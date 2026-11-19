/*
Now playing:
Offset - One Way Flight (feat. Tommy Richman) [GMFU]
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

int tab[1 << 18][18];
int len[18];

void answf() {
    droptop(i, 1, 19)
    {
        if (len[i] < (1 << i)) {
            cout << i << "\n";
            return;
        }
    }
    cout << 19 << "\n";
}

void add(int i, const int &n, const string &s) {
    int cur = 0;
    droptop(j, 1, 19)
    {
        if (i + j > n)
            break;
        cur = (cur << 1) | (s[i + j - 1] - '0');
        tab[cur][j]++;
        if (tab[cur][j] == 1)
            len[j]++;
    }
}
void rem(int i, const int &n, const string &s) {
    int cur = 0;
    droptop(j, 1, 19)
    {
        if (i + j > n)
            break;
        cur = (cur << 1) | (s[i + j - 1] - '0');
        tab[cur][j]--;
        if (tab[cur][j] == 0)
            len[j]--;
    }
}

int f() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    droptop(i, 0, n)
    {
        add(i, n, s);
    }

    answf();
    while (m--) {
        int x;
        cin >> x, x--;
        // rem(max(0, x - 17), n, s), rem(max(0, x - 1), n, s);
        // s[x] = (s[x] == '0' ? '1' : '0');
        // add(max(0, x - 17), n, s), add(max(0, x - 1), n, s);

        int start_min = max(0, x - 17);
        int start_max = min(n - 1, x) + 1;
        droptop(i, start_min, start_max)
        {
            rem(i, n, s);
        }

        s[x] = (s[x] == '0' ? '1' : '0');

        droptop(i, start_min, start_max)
        {
            add(i, n, s);
        }
        answf();
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
