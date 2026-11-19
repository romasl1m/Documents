/*
Now playing:
mgk - forget me too (feat. Halsey) [Tickets To My Downfall]
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
#define int ll

struct s {
    int pref, suf, sum, res;
};
s mergef(s &a, s &b) {
    s cur;
    cur.res = max({a.res, b.res, a.suf + b.pref}),
    cur.pref = max({a.pref, a.sum + b.pref}),
    cur.suf = max(b.suf, a.suf + b.sum),
    cur.sum = a.sum + b.sum;
    return cur;
}

const int base = 200'001;
s tree[base << 1];

void f() {
    int n, q;
    cin >> n >> q;
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        tree[i + base] = {x, x, x, x};
    }

    for (int i = base - 1; i > 0; i--)
        tree[i] = mergef(tree[i << 1], tree[i << 1 | 1]);

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << max(0LL, tree[base + l - 1].res) << "\n";
            continue;
        }
        l += base - 1, r += base - 1;
        s ans1 = tree[l], ans2 = tree[r];

        while (l + 1 < r) {
            if (not(l & 1))
                ans1 = mergef(ans1, tree[l + 1]);
            if (r & 1)
                ans2 = mergef(tree[r - 1], ans2);
            l >>= 1, r >>= 1;
        }

        cout << max(0LL, mergef(ans1, ans2).res) << "\n";
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
