/*
Now playing:
Lil Peep - hellboy [HELLBOY]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

bool sqf(ll x) {
    ll r = sqrtl((long double)x);
    return r * r == x or (r + 1) * (r + 1) == x;
}

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &sub, const vector<int> &tab, ll &res, const ll &n) {
    vector<ll> subs;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, wec, sub, tab, res, n);
        subs.pb(sub[ss]);
        sub[w] += sub[ss];
    }
    subs.pb(n - sub[w]);

    // if (sqrtf(tab[w]) * sqrtf(tab[w]) < tab[w])
    //     return;
    if (not sqf(tab[w]))
        return;

    ll cur = 0, two = 0, three = 0;

    for (ll x : subs) {
        three += two * x,
            two += cur * x,
            cur += x;
    }
    res += three + two;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> tab(n + 1);
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

    vector<int> sub(n + 1, 1);
    ll res = 0;

    dfs(1, 0, wec, sub, tab, res, n);
    cout << res << "\n";
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
