/*
Now playing:
Artemas - time alone w u [getting up to no good]
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
    int n, k;
    cin >> n >> k;
    vector<int> tab(n + 1, 0);
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        tab[x]++;
    }

    droptop(i, 0, n + 1)
    {
        // cerr << i << " " << tab[i] << " " << k << " " << (k << 1) - 1 << endl;
        if (tab[i] >= (k << 1))
            continue;
        if (tab[i] == (k << 1) - 1) {
            cout << "yes";
            return 0;
        } else {
            cout << "no";
            return 0;
        }
    }
    cout << "no";
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
