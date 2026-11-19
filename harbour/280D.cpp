/*
Now playing:
Offset - Different Species (feat. Gunna) [KIARI]
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

const int base = (1 << 17);
struct node {
    int sum, maks, maksl, maksr,
        prefmaks, prefmaksr,
        sufmaks, sufmaksl;

    int min, minl, minr,
        prefmin, prefminr,
        sufmin, sufminl;
};

int tab[base];
struct tr {
    node nd;
    int lazy;
} tree[base << 1];

node init(int pos, int war) {
    node res;
    res.sum = war,
    res.maks = res.prefmaks = res.sufmaks = war,
    res.maksl = res.maksr = res.prefmaksr = res.sufmaksl = pos,

    res.min = res.prefmin = res.sufmin = war;
    res.minl = res.minr = res.prefminr = res.sufminl = pos;
    return res;
}

node merge(const node &l, const node &r) {
    node res;
    res.sum = l.sum + r.sum;

    res.maks = l.maks, res.maksl = l.maksl, res.maksr = l.maksr;
    // mixin is better so we take the middle.
    if (r.maks > res.maks)
        res.maks = r.maks, res.maksl = r.maksl, res.maksr = r.maksr;
    if (l.sufmaks + r.prefmaks > res.maks)
        res.maks = l.sufmaks + r.prefmaks,
        res.maksl = l.sufmaksl,
        res.maksr = r.prefmaksr;

    // left sum,right prefix.
    res.prefmaks = l.prefmaks, res.prefmaksr = l.prefmaksr;
    if (l.sum + r.prefmaks > res.prefmaks)
        res.prefmaks = l.sum + r.prefmaks,
        res.prefmaksr = r.prefmaksr;

    // left suffix,whole right.
    res.sufmaks = r.sufmaks, res.sufmaksl = r.sufmaksl;
    if (l.sufmaks + r.sum > res.sufmaks)
        res.sufmaks = l.sufmaks + r.sum,
        res.sufmaksl = l.sufmaksl;

    // same with minimum.
    res.min = l.min, res.minl = l.minl, res.minr = l.minr;
    if (r.min < res.min)
        res.min = r.min, res.minl = r.minl, res.minr = r.minr;
    if (l.sufmin + r.prefmin < res.min)
        res.min = l.sufmin + r.prefmin, res.minl = l.sufminl, res.minr = r.prefminr;
    res.prefmin = l.prefmin, res.prefminr = l.prefminr;
    if (l.sum + r.prefmin < res.prefmin)
        res.prefmin = l.sum + r.prefmin, res.prefminr = r.prefminr;

    res.sufmin = r.sufmin, res.sufminl = r.sufminl;
    if (l.sufmin + r.sum < res.sufmin)
        res.sufmin = l.sufmin + r.sum, res.sufminl = l.sufminl;

    return res;
}

void negf(int w) {
    tree[w].nd.sum = -tree[w].nd.sum;

    swap(tree[w].nd.maks, tree[w].nd.min);
    tree[w].nd.maks *= -1,
        tree[w].nd.min *= -1;
    swap(tree[w].nd.maksl, tree[w].nd.minl),
        swap(tree[w].nd.maksr, tree[w].nd.minr);

    swap(tree[w].nd.prefmaks, tree[w].nd.prefmin);
    tree[w].nd.prefmaks *= -1,
        tree[w].nd.prefmin *= -1;
    swap(tree[w].nd.prefmaksr, tree[w].nd.prefminr);

    swap(tree[w].nd.sufmaks, tree[w].nd.sufmin);
    tree[w].nd.sufmaks *= -1,
        tree[w].nd.sufmin *= -1;
    swap(tree[w].nd.sufmaksl, tree[w].nd.sufminl);

    tree[w].lazy ^= 1;
}

void push(int w) {
    if (tree[w].lazy == 0)
        return;
    negf(w << 1);
    negf(w << 1 | 1);
    tree[w].lazy = 0;
}

void build(int w, int l, int r) {
    tree[w].lazy = 0;
    if (l == r) {
        tree[w].nd = init(l, tab[l]);
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(w << 1, l, mid);
    build(w << 1 | 1, mid + 1, r);

    tree[w].nd = merge(tree[w << 1].nd, tree[w << 1 | 1].nd);
}

void upd(int w, int l, int r, int pos, int war) {
    if (l == r) {
        tree[w].nd = init(pos, war);
        return;
    }
    push(w);

    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
        upd(w << 1, l, mid, pos, war);
    else
        upd(w << 1 | 1, mid + 1, r, pos, war);
    tree[w].nd = merge(tree[w << 1].nd, tree[w << 1 | 1].nd);
}

void updneg(int w, int l, int r, int a, int b) {
    if (a > b)
        return;
    if (a <= l and r <= b) {
        negf(w);
        return;
    }
    push(w);

    int mid = l + ((r - l) >> 1);
    if (a <= mid)
        updneg(w << 1, l, mid, a, b);
    if (b > mid)
        updneg(w << 1 | 1, mid + 1, r, a, b);
    tree[w].nd = merge(tree[w << 1].nd, tree[w << 1 | 1].nd);
}

node query(int w, int l, int r, int a, int b) {
    if (a <= l and r <= b)
        return tree[w].nd;
    push(w);

    int mid = l + ((r - l) >> 1);
    if (b <= mid)
        return query(w << 1, l, mid, a, b);
    if (a > mid)
        return query(w << 1 | 1, mid + 1, r, a, b);
    return merge(query(w << 1, l, mid, a, b), query(w << 1 | 1, mid + 1, r, a, b));
}

void f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    build(1, 1, n);

    // for (int i = base - 1; i > 0; i--) {
    //     tree[i] = merge(tree[i << 1], tree[i << 1 | 1], 20);
    // }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (not x) {
            int pos, cur;
            cin >> pos >> cur;
            upd(1, 1, n, pos, cur);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            // continue;
            // node res = query(1, 0, base - 1, l - 1, r - 1, k);
            // node res = query(l - 1, r - 1, k);
            int ans = 0;
            vector<pair<int, int>> ranges;

            droptop(kk, 0, k)
            {
                // droptop(i, 0, 2)
                // {
                //     droptop(j, 0, 2)
                //     {
                //         ans = max(ans, res.dp[kk][i][j]);
                //     }
                // }
                node best = query(1, 1, n, l, r);
                if (best.maks <= 0)
                    break;

                ans += best.maks;
                ranges.pb({best.maksl, best.maksr});
                updneg(1, 1, n, best.maksl, best.maksr);
            }

            for (const auto &[l, r] : ranges) {
                updneg(1, 1, n, l, r);
            }

            cout << max(0, ans) << "\n";
        }
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
