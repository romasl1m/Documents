/*
Now playing:
Linkin Park - QWERTY [QWERTY (Live in Tokyo, 2006)]
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

int tab[100'001];

void add1(int a, int d, int l) {
    int cur = a;
    droptop(i, 0, l)
    {
        tab[cur]++, cur += d;
    }
}

vector<pair<int, int>> wec[320];
void f() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int a, d, l;
        cin >> a >> l >> d;

        if (d >= 320)
            add1(a, d, l);
        else
            wec[d].pb({a, l});
    }

    droptop(i, 1, 320)
    {
        vector<int> cur(n + i + 1);
        for (const auto &[l, r] : wec[i]) {
            // cerr << cur.size() << " " << l << " " << l +
            cur[l]++, cur[l + i * r]--;
        }

        droptop(j, 1, n + i + 1)
        {
            if (j >= i)
                cur[j] += cur[j - i];
            tab[j] += cur[j];
        }
    }

    droptop(i, 1, n + 1)
    {
        cout << tab[i] << " ";
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
