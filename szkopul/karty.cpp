/*
Now playing:
Denzel Curry - Gook [Imperial]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

struct s {
    int a, b;
};
bool comp(s a, s b) {
    return (a.a == b.a ? a.b < b.a : a.a < b.a);
}
const int maks = (int)1e9;
s tab[(200'001 << 1) + 5];
int base = 1;
vector<s> tree[(200'001 << 2) + 5];

void f(vector<s> &a, vector<s> &b, vector<s> &c) {
    c.clear();
    droptop(i, 0, a.size())
    {
        droptop(j, 0, b.size())
        {
            if (a[i].b <= b[j].a)
                c.pb({a[i].a, b[j].b});
        }
    }

    if (c.empty())
        return;
    hotbox(c);
    c.erase(unique(c.begin(), c.end(), [](const s &l, const s &r) { return l.a == r.a and l.b == r.b; }), c.end());
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 0, n)
        {
            cin >> tab[i].a >> tab[i].b;
            if (tab[i].a > tab[i].b)
                swap(tab[i].a, tab[i].b);
        }

        while (base < n)
            base <<= 1;

        droptop(i, n, base)
        {
            tab[i] = {maks, maks};
        }
        droptop(i, 0, base)
        {
            tree[base + i].pb({tab[i].a, tab[i].a});
            if (tab[i].a != tab[i].b)
                tree[base + i].pb({tab[i].b, tab[i].b});
        }

        for (int i = base - 1; i >= 1; i--) {
            f(tree[i << 1], tree[i << 1 | 1], tree[i]);
        }

        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            swap(tab[a], tab[b]);
            swap(tree[base + a], tree[base + b]);

            int cur = (base + b) >> 1;
            while (cur > 0) {
                f(tree[cur << 1], tree[cur << 1 | 1], tree[cur]);
                cur >>= 1;
            }

            cur = (base + a) >> 1;
            while (cur > 0) {
                f(tree[cur << 1], tree[cur << 1 | 1], tree[cur]);
                cur >>= 1;
            }
            cout << (not tree[1].empty() ? "TAK\n" : "NIE\n");
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
