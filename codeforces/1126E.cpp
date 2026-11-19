/*
Now playing:
Linkin Park - LOST IN THE ECHO [LIVING THINGS]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int n, k;
bool checkf(int x, vector<pair<int, int>> &start, vector<pair<int, int>> &gen) {
    int cur = k + x - 1, cntstart = 0, cntgen = 0;
    gen.clear();
    int res, resgen;
    while (cntstart < start.size() or cntgen < gen.size()) {
        // int w,
    }
}

int f() {
    cin >> n >> k;
    vector<int> tab(n);
    vector<pair<int, int>> start, gen;
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    hotbox(tab);
    droptop(i, 0, n)
    {
        if (not start.empty() and start.back().first == tab[i])
            start.back().second++;
        else
            start.pb({tab[i], 1});
    }
    int maks = tab.front(), l = 0, r = ((maks + n + 2) >> 1) + 1;

    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        // if (checkf(n + (mid << 1)), start, gen)
        //     r = mid;
        // else
        //     l = mid + 1;
    }

    cout << n + (l << 1);
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
