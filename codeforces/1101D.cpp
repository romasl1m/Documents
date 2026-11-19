/*
Now playing:
Linkin Park - Sharp Edges [One More Light]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// bool comp(int a, int b) {
//     return a < b;
// }
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

int tab[200'001];
vector<int> wec[200'001];

int gcdf(int a, int b) {
    if (a < b)
        swap(a, b);
    while (b) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

vector<pair<int, int>> paths[200'001];
int res = 0;

void dfs(int w, int p) {
    vector<pair<int, int>> cur;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);

        for (const auto &x : paths[ss]) {
            cur.pb(x);
        }
    }
    hotbox(cur);

    droptop(l, 0, cur.size())
    {
        auto &path = cur[l];
        int r = l - 1, maks1 = 0, maks2 = 0;
        while (r + 1 < cur.size() and cur[r + 1].first == path.first) {
            r++;
            if (cur[r].second >= maks1) {
                maks2 = maks1, maks1 = cur[r].second;
            } else if (cur[r].second > maks2)
                maks2 = cur[r].second;
        }

        if (not(tab[w] % path.first)) {
            res = max(res, maks1 + maks2 + 1), paths[w].pb({path.first, maks1 + 1});
            while (not(tab[w] % path.first))
                tab[w] /= path.first;
        } else
            res = max(res, maks1);
        l = r;
    }

    for (int i = 2; i * i <= tab[w]; i++) {
        if (not(tab[w] % i)) {
            res = max(res, 1), paths[w].pb({i, 1});
            while (not(tab[w] % i))
                tab[w] /= i;
        }
    }
    if (tab[w] > 1) {
        res = max(res, 1), paths[w].pb({tab[w], 1});
    }
}

int f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0);
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
