/*
Now playing:
Young Thug - Digits [Slime Season 3]
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

int start[10'001];
int bef[10'001];
int perm[10'001];
bool wiz[10'001];

const int base = (1 << 14);
int tab[base << 1];

void add(int pos) {
    pos += base, tab[pos]++;
    for (pos >>= 1; pos > 0; pos >>= 1) {
        tab[pos] = tab[pos << 1] + tab[pos << 1 | 1];
    }
}

int query(int k) {
    int w = 1, sz = base;
    while (w < base) {
        sz >>= 1;
        int l = sz - tab[w << 1];
        if (k <= l) {
            w <<= 1;
        } else {
            k -= l, w = (w << 1) | 1;
        }
    }
    return w - base;
}

int ask(const int &a, const int &b) {
    cout << a << ' ' << b << endl;
    int x;
    cin >> x;
    if (x == 0)
        exit(0);
    return x;
}

void f() {
    int n;
    cin >> n;
    add(0);

    droptop(i, 1, n + 1)
    {
        start[i] = ask(i, 1);
    }

    droptop(i, 1, n + 1)
    {
        bef[i] = (i - 1 - start[1] + start[i]) >> 1;
    }

    for (int i = n; i > 0; i--) {
        perm[i] = query(bef[i] + 1);
        add(perm[i]);
    }

    // swap(perm[1], perm[n]), ask(1, n);
    int last = perm[n];
    for (int i = n; i > 1; i--)
        perm[i] = perm[i - 1];
    perm[1] = last;

    droptop(i, 1, n + 1)
    {
        while (perm[i] != i) {
            int targ = perm[i];
            swap(perm[i], perm[targ]);
            ask(i, targ);
        }
    }
}

int main() {
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
