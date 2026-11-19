/*
Now playing:
21 Savage - Darth Vader [Without Warning]
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
    int n, k;
    cin >> n >> k;
    vector<int> tab(n + 1);
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        tab[x]++;
        // cin >> tab[i];
    }

    int res = 0, cur = 0;
    droptop(i, 0, n + 1)
    {
        cur += tab[i];
        if (not tab[i] or cur < k)
            break;
        cur -= k, res = i + 1;
    }
    cout << res;

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
