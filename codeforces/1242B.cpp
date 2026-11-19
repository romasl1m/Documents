/*
Now playing:
Offset - One Way Flight (feat. Tommy Richman) [GMFU]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

vector<int> wec[100'001];
int tab[100'001], siz[100'001];

int findf(int x) {
    if (tab[x] == x)
        return x;
    return findf(tab[x]);
}

void uniof(int a, int b, set<int> &s) {
    a = findf(a), b = findf(b);
    tab[b] = a, siz[a] += siz[b], siz[b] = false, s.erase(b);
}

int f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            wec[a].pb(b);
        else
            wec[b].pb(a);
    }
    droptop(w, 1, n + 1)
    {
        siz[w] = 1, tab[w] = w;
    }

    set<int> components;
    droptop(w, 1, n + 1)
    {
        components.insert(w);
        unordered_map<int, int> expensive;
        for (int ss : wec[w]) {
            expensive[findf(ss)]++;
        }
        vector<int> cur;
        for (const auto &ss : components) {
            if (expensive[ss] < siz[ss] and ss != w)
                cur.pb(ss);
            // uniof(ss, w, components);
        }
        for (int ss : cur) {
            uniof(ss, w, components);
        }
    }
    return components.size() - 1;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
