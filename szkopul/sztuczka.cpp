/*
Now playing:
Juice WRLD - Feline (with Polo G & Trippie Redd) [Fighting Demons (Deluxe)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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

unordered_set<ll> s;

bool checkf(ll int x, const ll &pref) {
    ll st = x;
    for (; x <= pref; x += st) {
        if (s.find(x) == s.end())
            return false;
    }
    return true;
}

ll f() {
    int n;
    cin >> n;

    ll pref = 0;
    droptop(i, 0, n)
    {
        ll x;
        cin >> x;
        pref += x, s.insert(pref);
    }

    vector<ll> stk;
    for (ll i = 1; i * i <= pref; i++) {
        if (not(pref % i)) {
            if (checkf(i, pref))
                return pref / i;
            stk.pb(pref / i);
        }
    }

    while (not stk.empty()) {
        ll x = stk.back();
        stk.pop_back();

        if (checkf(x, pref)) {
            return pref / x;
        }
    }

    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
