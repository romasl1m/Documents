/*
Now playing:
Linkin Park - Burning in the Skies [A Thousand Suns]
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
#define int ll

struct post {
    int pos, h;
};
post tab[200'001];
post temp[200'001];

struct wert {
    int cnt, sum;
};
const ll base = 200'001;
wert tree[base << 1];
vector<int> wart;

void add(int pos, int cnt, int war) {
    pos += base;
    tree[pos].cnt += cnt;
    tree[pos].sum += cnt * war;
    while (pos > 1) {
        pos >>= 1;
        tree[pos].cnt = tree[pos << 1].cnt + tree[pos << 1 | 1].cnt;
        tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
    }
}

ll query(int w, int k, vector<int> wart) {
    if (k <= 0)
        return tree[w].sum;
    if (k >= tree[w].cnt)
        return 0;
    if (w >= base) {
        int id = w - base;
        int rem = tree[w].cnt - k;
        return rem * wart[id];
    }
    if (tree[w << 1 | 1].cnt <= k) {
        return query(w << 1, k - tree[w << 1 | 1].cnt, wart);
    } else {
        return tree[w << 1].sum + query(w << 1 | 1, k, wart);
    }
}

int getid(ll x) {
    return lower_bound(wart.begin(), wart.end(), x) - wart.begin();
}

bool ok(const ll &ch, const ll &cl, const ll &sh, const ll &sl, const vector<ll> &wart, const ll &hg, const ll &lw) {
    if (ch <= sh) {
        ll brak = sh - ch, lneed = sl + brak * (hg / lw);
        return lneed <= cl;
    } else {
        ll extrahg = ch - sh;
        ll remsl = query(1, extrahg, wart);
        return remsl <= cl;
    }
    return false;
}

ll f(ll n, ll cnt1, ll h1, ll cnt2, ll h2) {
    ll hg = max(h1, h2), lw = min(h1, h2),
       ch = (h1 == hg) ? cnt1 : cnt2, cl = (h1 == hg) ? cnt2 : cnt1;

    vector<int> d(n - 1);
    ll zasieg = tab[0].pos + tab[0].h;
    droptop(i, 0, n - 1)
    {
        zasieg = max(zasieg, tab[i].pos + tab[i].h);
        d[i] = max(0LL, tab[i + 1].pos - zasieg);
    }

    vector<ll> rawneed(n - 1);
    droptop(i, 0, n - 1)
    {
        ll modc = d[i] % hg;
        rawneed[i] = (modc + lw - 1) / lw;
    }
    wart = rawneed;
    hotbox(wart);
    wart.erase(unique(wart.begin(), wart.end()), wart.end());
    if (wart.size() == 0)
        return 0;

    ll sh = 0, sl = 0;
    ll l = 0, maks = 1;

    droptop(r, 0, n - 1)
    {
        ll full = d[r] / hg, lneed = rawneed[r], id = getid(lneed);

        sh += full, sl += lneed;
        add(id, 1, wart[id]);

        while (l <= r and not ok(ch, cl, sh, sl, wart, hg, lw)) {
            ll lfull = d[l] / hg, llneed = rawneed[l], idl = getid(llneed);
            sh -= lfull, sl -= llneed;

            add(idl, -1, wart[idl]);
            l++;
            // auto it = find(mod.begin(), mod.end(), llneed);
            // if (it != mod.end()) {
            //     mod.erase(it);
            // }
            // l++;
        }
        maks = max(maks, r - l + 2);
    }
    return maks;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;

        droptop(i, 0, n)
        {
            cin >> tab[i].pos >> tab[i].h;
        }

        int h1, cnt1, cnt2, h2;
        cin >> cnt1 >> h1 >> cnt2 >> h2;

        if (n == 1) {
            cout << cnt1 + cnt2 + 1;
            return 0;
        }
        ll res = f(n, cnt1, h1, cnt2, h2);
        // droptop(r, 0, n - 1)
        // {
        //     sh += (tab[r + 1].pos - tab[r].pos - tab[r].h) / h1, sl += ((tab[r + 1].pos - tab[r].pos - tab[r].h) % h1 + h2 - 1) / h2;
        //     // while (cur > cnt) {
        //     //     cur -= f(l++, h1);
        //     // }
        //
        //         res = max(res, r - l + 1);
        // }

        droptop(i, 0, n)
        {
            temp[i].pos = -tab[n - 1 - i].pos;
            temp[i].h = tab[n - 1 - i].h;
        }
        droptop(i, 0, n)
        {
            tab[i] = temp[i];
        }
        droptop(i, 0, base << 1)
        {
            tree[i] = {0, 0};
        }
        res = max(res, f(n, cnt1, h1, cnt2, h2));

        cout << res + cnt1 + cnt2;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
