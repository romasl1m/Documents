/*
Now playing:
21 Savage - Darth Vader [Without Warning]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <random>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
bool comp(ll a, ll b) {
    return a < b;
}

mt19937_64 rng(1337);
void f() {
    int n, m;
    cin >> n >> m;
    vector<ll> pref(n);
    map<ll, int> mapa;
    deque<int> q;
    vector<int> dp(n), lst(n), res;

    droptop(i, 0, m)
    {
        int l, r;
        cin >> l >> r;
        // int cur = rand();
        ll int cur = rng();
        pref[l - 1] ^= cur;
        if (r < n)
            pref[r] ^= cur;
    }
    droptop(i, 1, n)
    {
        pref[i] ^= pref[i - 1];
    }

    q.pb(0), mapa[pref[false]] = false;
    int cur = n, ed = -1;

    droptop(i, 1, n)
    {
        lst[i] = q.front(), dp[i] = dp[q.front()] + 1;
        if (mapa.count(pref[i])) {
            int par = mapa[pref[i]];
            cur = min(cur, par), ed = i;
            while (not q.empty() and q.front() <= par)
                q.pop_front();
        }

        if (not q.empty() and dp[i] > q.front())
            lst[i] = q.front();
        while (not q.empty() and dp[i] < dp[q.back()])
            q.pop_back();
        mapa[pref[i]] = i, q.pb(i);
    }

    int icur = q.front();
    for (int i = q.front(); i > 0; i = lst[i])
        res.pb(i);
    if (ed != -1 and pref[cur] == pref[ed])
        res.pb(cur);

    if (res.size() & 1)
        res.pb(n);
    hotbox(res);
    int pol = (res.size() >> 1);

    cout << pol << "\n";
    droptop(i, 0, pol)
    {
        cout << res[i] + 1 << " " << res[i + pol] << "\n";
    }
}

signed main() {
    srand(time(NULL));
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}
