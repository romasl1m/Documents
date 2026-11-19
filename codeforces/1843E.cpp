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

int f() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> wec(m);
    droptop(i, 0, m)
    {
        cin >> wec[i].first >> wec[i].second;
    }

    int q;
    cin >> q;
    vector<int> tab(q), pref(n + 1);
    droptop(i, 0, q)
    {
        cin >> tab[i];
    }

    int l = 0, r = q + 1;
    while (l < r - 1) {
        int mid = l + ((r - l) >> 1);
        droptop(i, 0, n + 1)
        {
            pref[i] = 0;
        }
        droptop(i, 0, mid)
        {
            pref[tab[i]]++;
        }
        droptop(i, 0, n)
        {
            pref[i + 1] += pref[i];
        }

        bool ok = false;
        droptop(i, 0, m)
        {
            int cur = pref[wec[i].second] - pref[wec[i].first - 1];
            if (cur > ((wec[i].second - wec[i].first + 1) >> 1)) {
                r = mid, ok = true;
                break;
            }
        }
        if (not ok)
            l = mid;
    }
    return (r == q + 1 ? -1 : r);
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
