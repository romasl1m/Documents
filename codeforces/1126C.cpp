/*
Now playing:
Bring Me The Horizon - Run [That's The Spirit]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
bool comp(ll int a, ll int b) {
    return a < b;
}
ll inff(ll x, const vector<ll> &l, const vector<ll> &r, const vector<ll> &pref) {
    int idx = upper_bound(l.begin(), l.end(), x) - l.begin();
    if (!idx)
        return 0;
    return pref[idx - 1] + min(x, r[idx - 1]) - l[idx - 1] + 1;
}

int f() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> wec;
    vector<ll> pref(n + 1), l(n), r(n);
    wec.reserve(n);

    droptop(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        l[i] = a, r[i] = b, wec.pb({a, b}), pref[i + 1] = pref[i] + b - a + 1;
    }

    if (k == 0) {
        cout << r[n - 1] + 1;
        return 0;
    }
    vector<ll> cnds;
    cnds.reserve(4 * n + 1);
    cnds.pb(1);
    droptop(i, 0, n)
    {
        ll cand[4] = {l[i], r[i] + 1, l[i] - m, r[i] + 1 - m};
        for (ll x : cand)
            if (x >= 1)
                cnds.pb(x);
    }
    hotbox(cnds);
    cnds.erase(unique(cnds.begin(), cnds.end()), cnds.end());

    int sz = cnds.size();
    vector<ll> war(sz);
    droptop(i, 0, sz)
    {
        war[i] = inff(cnds[i] + m - 1, l, r, pref) - inff(cnds[i] - 1, l, r, pref);
    }

    droptop(i, 0, sz - 1)
    {
        ll a = cnds[i], b = war[i], c = war[i + 1];
        if (k < min(b, c) or k > max(b, c))
            continue;
        if (b == c)
            cout << a;
        else if (c > b)
            cout << a + (k - b);
        else
            cout << a + (b - k);
        return 0;
    }
    cout << -1;
    return 0;
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
