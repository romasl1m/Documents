/*
Now playing:
Otsochodzi - WIĘCEJ NIEBA [RIOTT]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

vector<int> par, siz, tab;

int fin(int w) {
    if (par[w] == w)
        return w;
    return par[w] = fin(par[w]);
}

void unio(int a, int b) {
    a = fin(a), b = fin(b);
    if (a != b) {
        if (tab[b] > tab[a])
            swap(a, b);
        par[b] = a, siz[a] += siz[b];
        if (tab[a] == tab[b])
            tab[a]++;
    }
}

int subsiz(int x) {
    x = fin(x);
    return ((siz[x] - 1) * siz[x]) >> 1;
}

void f() {
    int n;
    cin >> n;
    par.resize(n, 0), siz.resize(n, 0), tab.resize(n, 0);

    map<int, vector<int>> diffs;
    int last = 0;
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        if (last > 0)
            diffs[abs(x - last)].pb(i);
        last = x;
    }

    droptop(i, 0, n)
    {
        siz[i] = 1, tab[i] = 0, par[i] = i;
    }

    vector<ll> res;
    ll cur = 0;
    cookie(i, n - 1, 1)
    {
        for (const auto &x : diffs[i]) {
            cur -= (subsiz(x) + subsiz(x - 1)),
                unio(x, x - 1),
                cur += subsiz(x);
        }
        res.pb(cur);
    }

    cookie(i, res.size() - 1, 0)
    {
        cout << res[i] << " ";
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
