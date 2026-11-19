/*
Now playing:
PnB Rock - Nowadays [TrapStar Turnt PopStar]
*/
#include <iostream>
#include <algorithm>
#include <vector>
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
struct sp {
    int x, y;
    bool typ;
    int id;
};
// int tx[] = {0, 1, 0, -1}, ty[] = {1, 0, -1, 0};
int n, m;

// void dfs(sp w, sp p = {-1, -1}) {
//     droptop(0, 4)
//     {
//         int a = w.x + tx[i], b = w.y + ty[i];
//         if (a < 0 or b < 0 or a > n - 1 or b > m - 1)
//             continue;
//         if (wiz[a][b]) {
//             dp[a][b]++;
//         }
//     }
// }

vector<sp> wec;
vector<sp> bet;
vector<sp> wrs;
int par[2'000'011];
char res[2'000'011];
int find(int x) {
    return (par[x] == x) ? x : (par[x] = find(par[x]));
}
bool unio(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
        return false;
    par[a] = b;
    return true;
}

int main() {
    raindrop;
    cin >> m >> n;
    int cur = 0;
    droptop(0, m)
    {
        for (int j = 0; j < n - 1; j++) {
            char c;
            cin >> c;
            int y = i * n + j + 1, x = i * n + j;
            wec.pb({x, y, (c == 'T' ? true : false), cur++});
        }
    }
    droptop(0, m - 1)
    {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            int x = i * n + j, y = (i + 1) * n + j;
            wec.pb({x, y, (c == 'T' ? true : false), cur++});
        }
    }
    droptop(0, n * m)
    {
        par[i] = i;
    }
    cur = wec.size();
    for (auto &x : wec) {
        x.typ ? bet.pb(x) : wrs.pb(x);
    }
    int cis = 0, sum = 0;
    for (const auto &x : bet) {
        if (unio(x.x, x.y)) {
            res[x.id] = '.';
        } else {
            res[x.id] = 'Z';
            sum++;
        }
    }

    for (const auto &x : wrs) {
        if (unio(x.x, x.y)) {
            res[x.id] = '.';
        } else {
            res[x.id] = 'Z';
            cis++;
            sum++;
        }
    }
    int idx = 0;
    cout << sum << " " << cis << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << res[idx++];
        }
        cout << "\n";
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[idx++];
        }
        cout << "\n";
    }
    return 0;
}
