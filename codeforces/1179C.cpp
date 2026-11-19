/*
Now playing:
Offset - NIGHT VISION [SET IT OFF]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

const int base = 1e6 + 1;
int tree[base << 2], lazy[base << 2];
int a[300'001], b[300'001];

void pushf(int w) {
    if (lazy[w])
        lazy[w << 1] += lazy[w], lazy[w << 1 | 1] += lazy[w], tree[w << 1] += lazy[w], tree[w << 1 | 1] += lazy[w], lazy[w] = 0;
}

void upd(int w, int l, int r, int a, int b, int war) {
    if (r < a or l > b)
        return;
    if (a <= l and r <= b) {
        lazy[w] += war, tree[w] += war;
        return;
    }

    int mid = l + ((r - l) >> 1);
    pushf(w);
    upd(w << 1, l, mid, a, b, war), upd(w << 1 | 1, mid + 1, r, a, b, war);
    tree[w] = max(tree[w << 1], tree[w << 1 | 1]);
}

int query(int w, int l, int r) {
    if (tree[w] < 1)
        return -1;
    if (l == r)
        return l;

    int mid = l + ((r - l) >> 1);
    pushf(w);
    if (tree[w << 1 | 1] >= 1)
        return query(w << 1 | 1, mid + 1, r);
    return query(w << 1, l, mid);
}

int f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 0, n)
    {
        cin >> a[i];
    }
    droptop(i, 0, m)
    {
        cin >> b[i];
    }

    droptop(i, 0, n)
    {
        upd(1, 0, base - 1, 0, a[i], 1);
    }
    droptop(i, 0, m)
    {
        upd(1, 0, base - 1, 0, b[i], -1);
    }

    int q;
    cin >> q;
    while (q--) {
        int cur, l, r;
        cin >> cur >> l >> r, l--;
        if (cur == 1) {
            upd(1, 0, base - 1, 0, a[l], -1),
                a[l] = r,
                upd(1, 0, base - 1, 0, a[l], 1);
        } else {
            upd(1, 0, base - 1, 0, b[l], 1),
                b[l] = r,
                upd(1, 0, base - 1, 0, b[l], -1);
        }
        cout << query(1, 0, base - 1) << "\n";
    }
    return 67;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
