/*
Now playing:
mgk - your name forever [your name forever]
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

ll int f() {
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    ll res = 0;

    droptop(i, 0, n)
    {
        cin >> a[i];
    }
    droptop(i, 0, n)
    {
        cin >> b[i];
    }

    vector<int> lasta(n + 2, n), lastb(n + 2, n), dp(n + 2, n);

    cookie(i, n - 1, 0)
    {
        lasta[a[i]] = lastb[b[i]] = i;
        if (a[i] == b[i]) {
            int nxt = a[i] + 1;
            if (lasta[nxt] == lastb[nxt])
                dp[i] = dp[lasta[nxt]];
            else
                dp[i] = min(lasta[nxt], lastb[nxt]);
        }

        res += (lasta[1] == lastb[1] ? dp[lasta[1]] : min(lasta[1], lastb[1])) - i;
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
