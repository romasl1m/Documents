/*
Now playing:
MORGENSHTERN - DALEKO [DALEKO]
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

bool checkf(int pos, const int &mid, const int &k, const int &n, const vector<int> &tab) {
    int res = 0, cur = mid;
    droptop(i, pos, n)
    {
        if (cur <= tab[i])
            break;
        if (i == n - 1)
            return false;
        res += cur - tab[i], cur = max(0, cur - 1);
        if (res > k)
            return false;
    }
    if (res <= k)
        return true;
    return false;
}

int f() {
    int n, k;
    cin >> n >> k;
    vector<int> tab(n);
    int res = 0;
    droptop(i, 0, n)
    {
        cin >> tab[i], res = max(res, tab[i]);
    }

    int l = 0, r = 2e8;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        bool ok = false;
        droptop(i, 0, n - 1)
        {
            if (checkf(i, mid, k, n, tab)) {
                l = mid + 1, res = max(res, mid), ok = true;
                break;
            }
        }
        if (not ok)
            r = mid - 1;
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
