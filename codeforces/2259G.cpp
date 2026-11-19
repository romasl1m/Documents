/*
Now playing:
Rammstein - Das Modell [Raritäten (1994 - 2012)]
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
#define int ll

int f() {
    int n, k;
    cin >> n >> k;
    vector<ll> tab(n + 1), pref(n + 1), res(n + 1), maks(n + 1);
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
        pref[i] = pref[i - 1] + tab[i];
        maks[i] = tab[i] - i * k;
    }

    droptop(i, 2, n)
    {
        int l = i + 1, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (maks[mid] <= (tab[i - 1] - i * k))
                r = mid - 1;
            else
                l = mid + 1;
        }

        ll cur = l - i - 1;
        // cerr << endl
        //      << cur << endl;
        res[i] = (pref[cur + i] - pref[i]) - (k * (cur * (cur + 1)) >> 1) - tab[i - 1] * cur;
        // max(0, pref[n] - pref[i] - (n - i) * tab[i - 1] - ((k * (n - i) * (n - i + 1)) >> 1));
    }
    droptop(i, 1, n + 1)
    {
        cout << res[i] << " ";
    }
    // cout << "0 ";
    // droptop(i, 2, n)
    // {
    //     // cerr << pref[n] - pref[i] - (n - i) * tab[i - 1] - ((k * (n - i) * (n - i + 1)) >> 1) << endl;
    //     cout << max(0, pref[n] - pref[i] - (n - i) * tab[i - 1] - ((k * (n - i) * (n - i + 1)) >> 1)) << " ";
    // }
    // cout << "0 ";
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
