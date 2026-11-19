/*
Now playing:
Fukaj - NIE CHCĘ WRACAĆ [INTERLUDIUM]
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

const int base = 200'001;
ll tree[base << 1];

ll nwd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    while (b) {
        ll c = a % b;
        a = b, b = c;
    }
    return a;
}

// void build(const int &n) {
//     cookie(i, base - 1, 1)
//     {
//         tree[i] = nwd(tree[i << 1], tree[i << 1 | 1]);
//     }
// }

ll query(int l, int r, const int &n) {
    l += n - 1, r += n;
    ll res = false;
    while (l < r) {
        if (l & 1)
            res = nwd(res, tree[l++]);
        if (r & 1)
            res = nwd(res, tree[--r]);
        l >>= 1, r >>= 1;
    }
    return res;
}

int f() {
    int n;
    cin >> n;
    vector<ll> tab(n + 1);
    // droptop(i, 1, (base << 1))
    // {
    //     tree[i] = false;
    // }
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }

    droptop(i, 0, n - 1)
    {
        tree[n - 1 + i] = abs(tab[i] - tab[i + 1]);
    }
    cookie(i, n - 2, 1)
    {
        tree[i] = nwd(tree[i << 1], tree[i << 1 | 1]);
    }
    // build(n);

    int res = 1;
    droptop(i, 0, n - 1)
    {
        if (tree[n - 1 + i] < 2)
            continue;
        int l = i, r = n - 2;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);
            if (query(i, mid, n) >= 2)
                l = mid;
            else
                r = mid - 1;
        }
        res = max(res, l - i + 2);
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
