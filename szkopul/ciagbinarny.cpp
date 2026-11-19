/*
Now playing:
Bring Me The Horizon - DArkSide [POST HUMAN: NeX GEn]
*/
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll pref[1'000'001];
ll pref1[1'000'001];
ll tab[1'000'001];
ll res[1'000'001];

struct st {
    ll id, l, r, k, a, b;
};
vector<st> zap;

ll binl(const ll &x, const ll &n) {
    return lower_bound(pref + 1, pref + n + 1, x) - pref;
}
ll binr(const ll &x, const ll &n) {
    return upper_bound(pref + 1, pref + n + 1, x) - pref;
}

ll k0(const ll &l, const ll &r, const int &a, const int &b) {
    if (a == b and (a & 1))
        return r - l + 1;
    return 0;
}
ll k1(const ll &l, const ll &r, const int &a, const int &b) {
    ll res = 0;

    if (a & 1)
        res = max(res, min(r, pref[a]) - l + 1);
    else if (a + 1 <= b)
        res = max(res, min(r, pref[a + 1]) - (pref[a] + 1) + 1);

    if (b & 1)
        res = max(res, r - max(l, pref[b - 1] + 1) + 1);
    else if (b - 1 >= a)
        res = max(res, pref[b - 1] - max(l, pref[b - 2] + 1) + 1);

    return res;
}
const int base = 1e6 + 1;
int tree[base << 1];
void cleart() {
    droptop(i, 0, base << 1)
    {
        tree[i] = 0;
    }
}
void upd(int idx, int war) {
    idx += base;
    tree[idx] += war;
    idx >>= 1;
    while (idx > 0) {
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
        idx >>= 1;
    }
}
ll query(int l, int r) {
    ll res = 0;
    l += base, r += base;

    res = tree[l];
    if (l != r)
        res += tab[r];

    while (l <= r) {
        if (l & 1)
            res += tree[l++];
        if (not(r & 1))
            res += tree[r--];
        l >>= 1, r >>= 1;
    }

    return res;
}
// ll f(ll l, ll r, ll k) {
//     return false;
// }

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, q;
        cin >> n >> q;

        droptop(i, 1, n + 1)
        {
            cin >> tab[i];
        }
        droptop(i, 1, n + 1)
        {
            pref[i] = pref[i - 1] + tab[i];
        }
        int last = 1;
        pref1[1] = tab[1];
        for (int i = 3; i <= n; i += 2, last++) {
            pref1[last + 1] = pref[last] + tab[i];
        }
        droptop(i, 0, q)
        {
            ll a, b, k;
            cin >> a >> b >> k;
            ll l = binl(a, n), r = binr(b, n);

            if (k == 0)
                res[i] = k0(a, b, l, r);
            else if (k == 1)
                res[i] = k1(a, b, l, r);
            else
                zap.pb({i, l, r, k, a, b});
        }

        const int &cnt = zap.size();
        if (cnt == 0) {
            droptop(i, 0, q)
            {
                cout << res[i] << "\n";
            }
            return 0;
        }

        vector<ll> ls(cnt, 1), rs(cnt, 1e6), ans(cnt);
        while (true) {
            bool active = false;
            vector<vector<ll>> qmid(1e6 + 1);

            droptop(i, 0, cnt)
            {
                if (ls[i] <= rs[i]) {
                    active = true;
                    const ll mid = ls[i] + ((rs[i] - ls[i]) >> 1);
                    if (mid < 1e6 + 1)
                        qmid[mid].pb(i);
                }
            }

            if (not active)
                break;

            cleart();
            droptop(i, 1, n + 1)
            {
                upd(i, tab[i]);

                // if (i < 1e6 + 1) {
                for (const ll &qidx : qmid[i]) {
                    const st &curq = zap[qidx];
                    const ll curwar = query(curq.l, curq.r);

                    if (curwar >= curq.k) {
                        ans[qidx] = curwar;
                        rs[qidx] = i - 1;
                    } else {
                        ls[qidx] = i + 1;
                    }
                }
                // }
            }
        }

        droptop(i, 0, cnt)
        {
            res[zap[i].id] = ans[i];
        }
        droptop(i, 0, q)
        {
            cout << res[i] << "\n";
        }

        return 0;
    }
}
