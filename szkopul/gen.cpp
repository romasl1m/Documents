#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char **argv) {
    mt19937_64 rng(atoll(argv[1]));
    auto R = [&](ll l, ll r) { return l + (ll)(rng() % (unsigned long long)(r - l + 1)); };

    int n = R(1, 100), k = R(1, 5);
    ll sc = (R(0, 3) == 0) ? 10000000000000000LL : 1;
    int cm = R(1, 6);

    vector<int> p(n);
    vector<ll> c(n), t(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        p[i] = R(1, k);
        c[i] = R(1, cm);
        total += c[i];
    }
    for (int i = 0; i < n; i++) {
        ll hi = max(c[i], total * R(3, 10) / 10);
        t[i] = R(c[i], hi);
    }
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++)
        cout << p[i] << " " << c[i] * sc << " " << t[i] * sc << "\n";
}
