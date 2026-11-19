/*
Now playing:
Linkin Park - All for Nothing (feat. Page Hamilton) [The Hunting Party]
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

vector<pair<int, int>> wec;
vector<pair<int, int>> res;
int tab[1'000'001], siz[1'000'001];

int findf(int a) {
    if (tab[a] == a)
        return a;
    return findf(tab[a]);
}

void unionf(int a, int b) {
    a = findf(a), b = findf(b);
    if (siz[b] > siz[a])
        swap(a, b);
    siz[a] += siz[b], tab[b] = a;
}
int f() {
    int n, m, k;
    cin >> n >> m >> k;
    droptop(i, 1, n + 1)
    {
        tab[i] = i;
    }
    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        if (a > k)
            unionf(a, b);
        else
            wec.pb({a, b});
    }

    for (const auto &[a, b] : wec) {
        int x = findf(a), y = findf(b);
        if (x != y)
            unionf(x, y);
        else
            res.pb({a, b});
    }

    cout << res.size() << "\n";
    for (const auto &[a, b] : res) {
        cout << a << " " << b << "\n";
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
