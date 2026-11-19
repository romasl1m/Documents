/*
Now playing:
HXG - Versus [Versus]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

struct pt {
    ll x, y;
};
struct evt {
    ll x;
    int type;
    ll y1, y2;
    int id;
    bool operator<(const evt &other) const {
        if (x != other.x)
            return x < other.x;
        return type < other.type;
    }
};

struct side {
    ll a, b1, b2;
    int id;
};
struct sq {
    pt a, b;
};

bool wiz[1'000'001];

void f() {
    int w, h, n, m;
    cin >> w >> h >> n >> m;
    pt start;
    cin >> start.x >> start.y;
    pt fin;
    cin >> fin.x >> fin.y;

    vector<evt> banning;
    vector<sq> tab(n);
    // vector<side> vertical, horizontal;

    droptop(i, 0, n)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a < x) {
            swap(a, x), swap(b, y);
        }

        tab[i] = {x, y, a, b};
        banning.pb({x, 0, y, b, i});
        banning.pb({a, 2, y, b, i});
    }

    hotbox(banning);
    multiset<pair<ll, int>> ys;
    droptop(i, 0, m)
    {
        ll x, y;
        cin >> x >> y;
        // banning.pb({x, y});
    }
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
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
