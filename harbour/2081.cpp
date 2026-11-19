/*
Now playing:
Lil Uzi Vert - Flooded The Face [Pink Tape]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

vector<int> wec[200'001];
int subs[200'001];
bool wiz[200'001];
const int base = 200'001;
ll freq[base << 1];

void add(int w) {
    w += base;
    freq[w]++, w >>= 1;
    while (w) {
        freq[w] = freq[w << 1] + freq[w << 1 | 1], w >>= 1;
    }
}

ll sumf(int a, int b) {
    a = max(0, a), b = min(base - 1, b);
    if (a > b)
        return 0;
    a += base, b += base;

    ll cur = 0;
    while (a <= b) {
        if (a & 1)
            cur += freq[a++];
        if (not(b & 1))
            cur += freq[b--];
        a >>= 1, b >>= 1;
    }
    return cur;
}

ll res = 0;
vector<int> ord;
int par[200'001];

void subsf(int w, int p) {
    ord.clear(), par[w] = -1, ord.pb(w);
    droptop(i, 0, (int)ord.size())
    {
        int w = ord[i];
        subs[w] = 1;
        for (int ss : wec[w]) {
            if (ss == par[w] or wiz[ss])
                continue;
            par[ss] = w, ord.pb(ss);
        }
    }
    cookie(i, (int)ord.size() - 1, 1)
    {
        subs[par[ord[i]]] += subs[ord[i]];
    }
}

vector<pair<int, int>> stk;
vector<int> dp;
void depf(int st, int cent, vector<int> &dep) {
    stk.clear(), dp.clear(), stk.pb({st, cent}), dp.pb(1), dep.pb(1);
    while (not stk.empty()) {
        auto [w, p] = stk.back();
        int d = dp.back();
        stk.pop_back(), dp.pop_back();

        for (int ss : wec[w]) {
            if (ss == p or wiz[ss])
                continue;
            dep.pb(d + 1), stk.pb({ss, w}), dp.pb(d + 1);
        }
    }
}

void f(int w, const int &l, const int &r) {
    subsf(w, -1);
    int cent = w, p = w;

    while (true) {
        bool ok = false;
        for (int ss : wec[cent]) {
            if (ss != p and not wiz[ss] and subs[ss] > (subs[w] >> 1)) {
                // cerr << "cent " << cent << " " << ss << " " << subs[w] << " " << subs[ss] << endl;
                p = cent, cent = ss, ok = true;
                break;
            }
        }
        if (not ok)
            break;
    }

    vector<int> depgl;
    add(false), depgl.pb(false);

    for (int ss : wec[cent]) {
        if (wiz[ss])
            continue;
        vector<int> dep;
        depf(ss, cent, dep);

        for (int &d : dep) {
            res += sumf(l - d, r - d);
            // if (d <= k and k - d < (int)freq.size())
            //     res += freq[k - d];
        }
        for (int &d : dep) {
            add(d), depgl.pb(d);
            // if (d <= k)
            //     freq[d]++;
        }
    }

    for (int &d : depgl) {
        int idx = base + d;
        freq[idx] = false, idx >>= 1;
        while (idx)
            freq[idx] = freq[idx << 1] + freq[idx << 1 | 1], idx >>= 1;
    }

    wiz[cent] = true;
    for (int ss : wec[cent]) {
        if (wiz[ss])
            continue;
        // cerr << "f " << ss << endl;
        f(ss, l, r);
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }
        f(1, l, r);
        cout << res;
    }
    return 0;
}
