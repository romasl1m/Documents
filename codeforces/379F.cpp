/*
Now playing:
Lil Peep - Hate Me [Come Over When You're Sober, Pt. 2]
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
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int lca[1'000'009][20];
int dep[1'000'009];

int lift(int b, int dif) {
    cookie(i, 19, 0)
    {
        if (dif & (1 << i))
            b = lca[b][i];
    }
    return b;
}

int lcaf(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    b = lift(b, dep[b] - dep[a]);
    if (a == b)
        return a;

    cookie(i, 19, 0)
    {
        if (lca[b][i] != 0 and lca[b][i] != lca[a][i])
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

int distf(int a, int b) {
    return dep[a] + dep[b] - (dep[lcaf(a, b)] << 1);
}

void f() {
    droptop(i, 2, 5)
    {
        dep[i] = lca[i][0] = 1;
    }

    int q;
    cin >> q;

    int a = 2, b = 3, dist = 2;

    int cur = 5;
    while (q--) {
        int w;
        cin >> w;

        int w1 = cur, w2 = cur + 1;
        dep[w1] = dep[w2] = dep[w] + 1;
        cur += 2;

        lca[w1][0] = lca[w2][0] = w;
        droptop(i, 1, 20)
        {
            lca[w1][i] = lca[w2][i] = lca[lca[w1][i - 1]][i - 1];
        }

        int dist1 = distf(w1, a), dist2 = distf(w1, b);

        // cerr << "futh. before: " << a << " " << b << endl;
        if (dist1 > dist)
            dist = dist1, b = w1;
        else if (dist2 > dist)
            dist = dist2, a = w1;

        cout << dist << "\n";
        // cerr << "futh. after: " << a << " " << b << endl;
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
