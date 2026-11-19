/*
Now playing:
Sentino - KATHARSIS [KATHARSIS]
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

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k, p, q;
        cin >> n >> k >> p >> q;
        vector<ll> tab(n + 1), a(n + 1), b(n + 1);
        droptop(i, 1, n + 1)
        {
            cin >> tab[i];
            a[i] = tab[i] % p % q, b[i] = tab[i] % q % p;
        }

        ll res = 1e18;
        vector<ll> pref(n + 1);
        droptop(i, 1, n + 1)
        {
            pref[i] = pref[i - 1] + min(a[i], b[i]);
        }
        droptop(i, 1, n + 1)
        {
            a[i] += a[i - 1], b[i] += b[i - 1];
        }
        droptop(i, k, n + 1)
        {
            res = min(res, min(a[i] - a[i - k], b[i] - b[i - k]) + pref[i - k] + pref[n] - pref[i]);
        }
        cout << res << "\n";
    }
}
