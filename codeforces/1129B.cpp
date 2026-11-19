/*
Now playing:
Artemas - superstar [LOVERCORE]
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
    vector<int> tab(n);
    int mint = 2e9;
    droptop(i, 0, n)
    {
        cin >> tab[i];
        mint = min(mint, tab[i]);
    }

    cout << (mint < n ? n : 0);

    int res = 0;
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
