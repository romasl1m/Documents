/*
Now playing:
Artemas - dirty little secret [yustyna]
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

string srtf(string s) {
    int len = s.length();
    vector<string> cur(len);
    droptop(i, 0, len)
    {
        cur[i] = string(1, s[i]);
    }

    while (cur.size() > 1) {
        vector<string> nxt;
        nxt.reserve(cur.size() >> 1);

        for (int i = 0; i < cur.size(); i += 2) {
            string l = cur[i], r = cur[i + 1];
            if (l > r)
                swap(l, r);
            nxt.pb(l + r);
        }
        cur = move(nxt);
    }
    return cur.front();
}

int f() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    auto checkf = [&](int l, int r, int la, int lb) -> bool {
        auto impl = [&](auto &&self, int l, int r, int la, int lb) -> bool {
            if (l == r)
                return a[l] == b[la];
            int mid = l + ((r - l) >> 1);
            int mida = la + ((lb - la) >> 1);
            if (self(self, l, mid, la, mida) and self(self, mid + 1, r, mida + 1, lb))
                return true;
            else
                return self(self, l, mid, mida + 1, lb) and self(self, mid + 1, r, la, mida);
        };
        return impl(impl, l, r, la, lb);
    };

    cout << (srtf(a) == srtf(b) ? "TAK\n" : "NIE\n");
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
