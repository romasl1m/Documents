/*
Now playing:
Lil Durk - Cross The Globe (feat. Juice WRLD) [Almost Healed]
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
    string a, b;
    cin >> n >> k >> a >> b;
    // vector<string> res;
    vector<int> lst(n, -1);
    // res.reserve(k);

    int cur = n - 1, moves = 0;
    cookie(i, n - 1, 0)
    {
        cur = min(cur, i);
        while (cur >= 0 and b[i] != a[cur])
            cur--;
        if (cur < 0) {
            cout << "-1\n";
            return 0;
        }
        lst[i] = cur;
        moves = max(moves, i - cur);
    }

    if (moves > k) {
        cout << "-1\n";
        return 0;
    }

    cout << moves << "\n";
    droptop(i, 0, moves)
    {
        cookie(j, n - 1, 1)
        {
            if (lst[j] != j)
                a[j] = a[j - 1], lst[j]++;
        }
        cout << a << "\n";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        // cout << "\n";
    }
    return 0;
}
