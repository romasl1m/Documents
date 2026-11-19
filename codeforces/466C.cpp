/*
Now playing:
Linkin Park - LOST IN THE ECHO [LIVING THINGS]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long
#define int ll

int tab[500'001];
ll pref[500'001];
int f() {
    int n;
    cin >> n;
    ll prefc = 0;
    droptop(i, 0, n)
    {
        cin >> tab[i];
        prefc += tab[i];
    }

    ll sum = prefc;
    if (sum % 3 != 0)
        return 0;
    sum /= 3;

    prefc = 0;
    droptop(i, 0, n)
    {
        prefc += tab[i];
        if (prefc == sum)
            pref[i] = 1;
    }
    droptop(i, 1, n)
    {
        pref[i] += pref[i - 1];
    }

    prefc = 0;
    ll res = 0;
    cookie(i, n - 1, 2)
    {
        prefc += tab[i];
        if (prefc == sum)
            res += pref[i - 2];
    }
    return res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
