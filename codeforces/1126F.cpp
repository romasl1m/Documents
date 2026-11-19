/*
Now playing:
Travis Scott - DA WIZARD [JACKBOYS 2]
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

bool checkf(const vector<int> &wec) {
    int cur = wec.size();
    vector<int> s, dif(cur + 1);
    cookie(i, cur - 1, 0)
    {
        while (not s.empty() and wec[s.back()] < wec[i])
            s.pop_back();
        if (not s.empty() and wec[s.back()] == wec[i]) {
            dif[i]++, dif[s.back() + 1]--;
        }
        s.pb(i);
    }

    int res = 0;
    droptop(i, 0, cur)
    {
        res += dif[i];
        if (res <= 0)
            return false;
    }
    return true;
}

int f() {
    int n;
    cin >> n;
    vector<int> tab(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }

    if (checkf(tab)) {
        cout << 0;
        return 0;
    }

    int maks = 0, pos = 0;
    droptop(i, 0, n)
    {
        if (tab[i] > maks) {
            maks = tab[i], pos = i;
        }
    }
    int cnt = 0;
    droptop(i, 0, n)
    {
        if (tab[i] == maks)
            cnt++;
    }

    vector<pair<int, int>> cur = {{0, maks}, {n - 1, maks}};
    if (cnt == 1)
        cur.pb({pos, 1});

    bool ok = false;
    for (const auto [i, x] : cur) {
        int old = tab[i];
        tab[i] = x;
        bool okcur = checkf(tab);
        tab[i] = old;

        if (okcur) {
            cout << "1\n"
                 << i + 1 << " " << x;
            ok = true;
            break;
        }
    }
    if (ok)
        return 0;
    cout << "2\n"
         << 1 << " " << maks << "\n"
         << n << " " << maks;
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
