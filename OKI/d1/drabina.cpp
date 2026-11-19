/*
Now playing:
Linkin Park - Let You Fade [From Zero (Deluxe Edition)]
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); ++c)
#define ll long long

inline int readInt() {
    int x = 0;
    int c = getchar_unlocked();

    while (c <= 32) {
        if (c == EOF)
            return 0;
        c = getchar_unlocked();
    }

    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar_unlocked();
    }
    return neg ? -x : x;
}

inline char readChar() {
    int c = getchar_unlocked();
    while (c <= 32) {
        if (c == EOF)
            return 0;
        c = getchar_unlocked();
    }
    return (char)c;
}

inline void write_int(int x) {
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    char buf[12];
    int ptr = 0;
    if (x == 0) {
        buf[ptr++] = '0';
    } else {
        while (x > 0) {
            buf[ptr++] = (char)('0' + (x % 10));
            x /= 10;
        }
    }
    while (ptr > 0) {
        putchar_unlocked(buf[--ptr]);
    }
    putchar_unlocked('\n');
}
int wtop[500'001];
int wbottom[500'001];
int wvert[500'001];

struct node {
    ll upup, updown, downup, downdown;
};

node tree[1 << 20];

node merge(const node &a, const node &b, int m) {
    node res;
    res.upup = min(a.upup + wtop[m] + b.upup, a.updown + wbottom[m] + b.downup);
    res.downdown = min(a.downdown + wbottom[m] + b.downdown, a.downup + wtop[m] + b.updown);
    res.updown = min(a.upup + wtop[m] + b.updown, a.updown + wbottom[m] + b.downdown);
    res.downup = min(a.downup + wtop[m] + b.upup, a.downdown + wbottom[m] + b.downup);
    return res;
}

void build(int w, int l, int r) {
    if (l == r) {
        tree[w] = {0, wvert[l], wvert[l], 0};
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(w << 1, l, mid);
    build(w << 1 | 1, mid + 1, r);
    tree[w] = merge(tree[w << 1], tree[w << 1 | 1], mid);
}

void update(int w, int l, int r, int pos) {
    if (l == r) {
        tree[w] = {0, wvert[l], wvert[l], 0};
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
        update(w << 1, l, mid, pos);
    else
        update(w << 1 | 1, mid + 1, r, pos);
    tree[w] = merge(tree[w << 1], tree[w << 1 | 1], mid);
}

node query(int w, int l, int r, int a, int b) {
    if (a <= l and r <= b)
        return tree[w];
    int mid = l + ((r - l) >> 1);
    if (b <= mid)
        return query(w << 1, l, mid, a, b);
    if (a > mid)
        return query(w << 1 | 1, mid + 1, r, a, b);

    return merge(query(w << 1, l, mid, a, b), query(w << 1 | 1, mid + 1, r, a, b), mid);
}

signed main() {
    raindrop;
    int n = readInt(), q = readInt();

    droptop(i, 1, n)
    {
        wtop[i] = readInt();
    }
    droptop(i, 1, n)
    {
        wbottom[i] = readInt();
    }
    droptop(i, 1, n + 1)
    {
        wvert[i] = readInt();
    }

    build(1, 1, n);

    while (q--) {
        char c = readChar();
        if (c == 'P') {
            int a = readInt(), b = readInt();
            if (a > b)
                swap(a, b);

            int c1 = (a + 1) >> 1;
            int c2 = (b + 1) >> 1;

            if (c1 == c2) {
                // cout << (a == b ? 0 : wvert[c1]) << "\n";
                write_int(a == b ? 0 : wvert[c1]);
            } else {
                auto cur = query(1, 1, n, c1, c2);

                if (a % 2 == 0 and b % 2 == 0) {
                    write_int(cur.downdown);
                    // cout << cur.downdown << "\n";
                } else if (a % 2 == 0 and b % 2 == 1) {
                    write_int(cur.downup);
                    // cout << cur.downup << "\n";
                } else if (a % 2 == 1 and b % 2 == 0) {
                    write_int(cur.updown);
                    // cout << cur.updown << "\n";
                } else {
                    write_int(cur.upup);
                    // cout << cur.upup << "\n";
                }
            }
        } else {
            int a = readInt(), b = readInt(), nowy = readInt();
            if (a > b)
                swap(a, b);

            int c1 = (a + 1) >> 1;
            if (b == a + 1 and a % 2 == 1) {
                wvert[c1] = nowy;
            } else if (b == a + 2) {
                if (a % 2 == 1)
                    wtop[c1] = nowy;
                else
                    wbottom[c1] = nowy;
            }
            update(1, 1, n, c1);
        }
    }
    return 0;
}
