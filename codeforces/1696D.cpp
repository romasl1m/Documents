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
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

int f() {
    int n;
    cin >> n;
    vector<int> tab(n + 2), pos(n + 1), pref(n + 2, 0), suf(n + 2, 0), minp(n + 2, 2e9), mins(n + 2, 2e9);
    droptop(i, 1, n + 1)
    {
        cin >> tab[i], pos[tab[i]] = i;
    }

    droptop(i, 1, n + 1)
    {
        minp[i] = min(minp[i - 1], tab[i]);
        pref[i] = max(pref[i - 1], tab[i]);
    }
    cookie(i, n, 1)
    {
        mins[i] = min(mins[i + 1], tab[i]);
        suf[i] = max(suf[i + 1], tab[i]);
    }

    bool cur = false;
    int x = pos[1], res = 0;
    while (x != 1) {
        res++;
        if (not cur)
            cur = true, x = pos[pref[x - 1]];
        else
            cur = false, x = pos[minp[x - 1]];
    }

    x = pos[1], cur = false;
    while (x != n) {
        res++;
        if (not cur)
            cur = true, x = pos[suf[x + 1]];
        else
            cur = false, x = pos[mins[x + 1]];
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
