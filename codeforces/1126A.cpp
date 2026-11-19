/*
Now playing:
mgk - bloody valentine [Tickets To My Downfall]
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

int f() {
    int a, b;
    cin >> a >> b;

    // if (a == 0) {
    // }
    // if (a < b - 1) {
    //     cout << "-1\n";
    //     return 0;
    // }
    // if (a == b and a == 0) {
    //     cout << "0\n";
    //     return 0;
    // }
    // cout << max({0, a, abs(b) - 1});

    if (b <= a and abs(a - b) % 2 == 0) {
        cout << a;
        return 0;
    } else if (b <= a + 1 and (abs(a - b) % 2 != 0)) {
        cout << a + 1;
        return 0;
    } else {
        cout << -1;
    }
    // if (not a) {
    //     if (not b) {
    //         cout << 0;
    //         return 0;
    //     } else if (b == 1) {
    //         cout << 1;
    //         return 0;
    //     } else {
    //         cout << -1;
    //         return 0;
    //     }
    // } else {
    //     if (b == 0) {
    //         cout << a + 1;
    //         return 0;
    //     } else if (b <= a + 1) {
    //         cout << max(a, b);
    //         return 0;
    //
    //     } else {
    //         cout << -1;
    //     }
    // }
    // cout << a << "\n";

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
