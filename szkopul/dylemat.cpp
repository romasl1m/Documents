/*
Now playing:
Lil Skies - Welcome to the Rodeo [Life of a Dark Rose]
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

const vector<pair<ll, ll>> hcl = {
    {1, 1}, {2, 2}, {6, 4}, {12, 6}, {60, 12}, {180, 18}, {360, 24}, {720, 30}, {1260, 36}, {2520, 48}, {7560, 64}, {10080, 72}, {15120, 80}, {25200, 90}, {27720, 120}, {50400, 108}, {55440, 120}, {83160, 128}, {110880, 144}, {166320, 160}, {277200, 180}, {332640, 192}, {498960, 240}, {554400, 216}, {665280, 224}, {720720, 240}, {1081080, 288}, {1441440, 288}, {2162160, 320}, {2882880, 336}, {3603600, 384}, {4324320, 384}, {6486480, 432}, {7207200, 480}};

ll nwd(ll a, ll b) {
    if (b > a)
        swap(a, b);
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void gen(ll pierwsza, ll pot, ll cur, ll d, vector<ll> &prime, vector<pair<ll, ll>> &cand, ll n, ll lim) {
    if (d >= lim) {
        cand.pb({cur, d});
    }
    droptop(i, pierwsza, prime.size())
    {
        ll p = prime[i];
        if (cur > n / p)
            break;
        ll nw = cur * p;
        ll exp = 1;
        while (nw <= n) {
            gen(i + 1, 1, nw, d * (exp + 1), prime, cand, n, lim);
            if (nw > n / p)
                break;
            nw *= p;
            exp++;
        }
    }
}

ll cnt(ll x) {
    if (x <= 0)
        return 0;
    if (x == 1)
        return 1;
    ll res = 2;
    for (ll i = 2; i * i <= x; i++) { // Zmiana z int na ll
        if (x % i == 0) {
            res += (x / i == i ? 1 : 2);
        }
    }
    return res;
}

ll limf(ll n) {
    ll maks = 1;
    for (const auto &i : hcl) {
        if (i.first <= n) {
            maks = max(maks, i.second);
        } else {
            break;
        }
    }
    return maks >> 1;
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        ll n;
        if (!(cin >> n))
            break;

        ll maks = 0;
        ll a = 1, b = 1;
        vector<pair<ll, ll>> cand;
        vector<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

        ll lim = limf(n);
        gen(0, 1, 1, 1, prime, cand, n, lim);

        // USUNIĘCIE DUPLIKATÓW - oszczędza mnóstwo RAMu i czasu
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        droptop(i, 0, cand.size())
        {
            droptop(j, i, cand.size())
            {
                auto [cura, dza] = cand[i];
                auto [curb, dzb] = cand[j];
                ll dznwd = cnt(nwd(cura, curb));
                ll unique_divs = dza + dzb - dznwd;
                if (unique_divs > maks) {
                    maks = unique_divs;
                    a = cura;
                    b = curb;
                }
            }
        }
        cout << maks << "\n"
             << a << " " << b << "\n";
    }
}
