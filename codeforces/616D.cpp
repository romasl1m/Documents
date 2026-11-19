/*
Now playing:
Travis Scott - MODERN JAM (feat. Teezo Touchdown) [UTOPIA]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <set>
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

int tab[500'001];
int cnt[500'001];

void f() {
    int n, k;
    cin >> n >> k;

    vector<int> tab2;
    tab2.reserve(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
        tab2.pb(tab[i]);
    }
    hotbox(tab2);
    tab2.erase(unique(tab2.begin(), tab2.end()), tab2.end());

    droptop(i, 0, n)
    {
        tab[i] = lower_bound(tab2.begin(), tab2.end(), tab[i]) - tab2.begin();
    }

    int l = 0, r = -1, cur = 0, res = 0;
    pair<int, int> lr = {0, 0};

    droptop(r, 0, n)
    {
        if (cnt[tab[r]]++ == 0)
            cur++;

        while (cur > k) {
            if (--cnt[tab[l]] == 0)
                cur--;
            l++;
        }

        if (r - l + 1 > res)
            lr = {l, r}, res = r - l + 1;
    }
    // if (res < r - l)
    //     res = r - l, lr = {l, r - 1};

    cout << lr.first + 1 << " " << lr.second + 1;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
