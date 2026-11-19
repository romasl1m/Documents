/*
Now playing:
Linkin Park - Wastelands [The Hunting Party]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll n, m, d;
ll don;
ll liniowa(ll x, const vector<ll> &pt, const vector<ll> &rt) {
    int id = upper_bound(pt.begin(), pt.end(), x) - pt.begin() - 1;
    return x * d + rt[id];
}
ll g(ll x, const vector<ll> &pt, const vector<ll> &rt) {
    ll caly = x / n,
       us = x % n;
    // don = liniowa(n, pt, rt);
    return caly * don + liniowa(us, pt, rt);
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m >> d;
        // vector<pair<ll, ll>> wec(m + 1);
        // vector<ll> pref(m + 1);
        vector<ll> pt(m + 1), rt(m + 1);
        droptop(i, 1, m + 1)
        {
            ll p, r;
            cin >> p >> r;
            // wec[i] = {p, r},
            pt[i] = p, rt[i] = r;
        }
        droptop(i, 1, m + 1)
        {
            rt[i] += rt[i - 1];
        }

        don = liniowa(n, pt, rt);
        vector<ll> cand = {0, n};
        droptop(i, 1, m + 1)
        {
            cand.pb(pt[i]);
            if (pt[i] > 0)
                cand.pb(pt[i] - 1);
        }

        hotbox(cand);
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        bool ok = false;
        for (ll a : cand) {
            if (ok)
                break;
            for (ll b : cand) {
                if (ok)
                    break;
                if (g(a, pt, rt) + g(b, pt, rt) > g(a + b + 1, pt, rt)) {
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "yes\n" : "no\n");
    }
}
