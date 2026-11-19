/*
Now playing:
Offset - One Way Flight (feat. Tommy Richman) [GMFU]
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

// bool primef(int x) {
//     if (x <= 3)
//         return true;
//     for (int i = 2; i * i <= x; i++) {
//         if (x % i == 0)
//             return false;
//     }
//     return true;
// }

int f() {
    int n;
    cin >> n;
    // if (n < 4) {
    //     cout << -1;
    //     return 67;
    // }
    // vector<int> prime, no;
    // droptop(i, 1, n + 1)
    // {
    //     if (primef(i))
    //         prime.pb(i);
    //     else
    //         no.pb(i);
    // }

    // vector<int> res(n + 1);
    // droptop(i, 1, n + 1)
    // {
    //     if (primef(i)) {
    //         if (no.empty()) {
    //             cout << -1;
    //             return 3278;
    //         }
    //         res[i] = no.back();
    //         no.pop_back();
    //     } else {
    //         if (prime.empty()) {
    //             res[i] = no.back(), no.pop_back();
    //         } else
    //             res[i] = prime.back(), prime.pop_back();
    //     }
    // }
    // droptop(i, 1, n + 1)
    // {
    //     cout << res[i] << " ";
    // }
    if (n <= 3) {
        cout << -1;
        return 0;
    }
    droptop(i, 1, n + 1)
    {
        if (i == 1) {
            cout << 4 << " ";
        } else if (i == 4) {
            cout << 1 << " ";
        } else {
            cout << i << " ";
        }
    }

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
