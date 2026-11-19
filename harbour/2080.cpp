/*
Now playing:
Lil Uzi Vert - Flooded The Face [Pink Tape]
*/
#include <pthread.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
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
ll res = 0;

void subsf(int w, int p) {
    subs[w] = 1;
    for (int ss : wec[w]) {
        if (ss == p or wiz[ss])
            continue;
        subsf(ss, w), subs[w] += subs[ss];
    }
}

void depf(int w, int p, int d, vector<int> &dep) {
    dep.pb(d);
    for (int ss : wec[w]) {
        if (ss == p or wiz[ss])
            continue;
        depf(ss, w, d + 1, dep);
    }
}

void f(int w, const int &k) {
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

    vector<ll> freq(subs[w] + 1);
    freq.front() = 1;
    for (int ss : wec[cent]) {
        if (wiz[ss])
            continue;
        vector<int> dep;
        depf(ss, cent, 1, dep);
        for (int &d : dep) {
            if (d <= k and k - d < (int)freq.size())
                res += freq[k - d];
        }
        for (int &d : dep) {
            if (d <= k)
                freq[d]++;
        }
    }

    wiz[cent] = true;
    for (int ss : wec[cent]) {
        if (wiz[ss])
            continue;
        // cerr << "f " << ss << endl;
        f(ss, k);
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }
        f(1, k);
        cout << res;
    }
    return 0;
}
