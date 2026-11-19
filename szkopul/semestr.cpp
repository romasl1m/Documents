/*
Now playing:
Bring Me The Horizon - Run [That's The Spirit]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// bool comp(int a, int b) {
//     return a < b;
// }
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

struct prt {
    int p, id;
    ll c, t;

    bool operator<(const prt &other) const {
        return t < other.t;
    }
};

vector<prt> wec;
vector<int> pos[20];
vector<vector<pair<ll, int>>> pref;
ll dif[1'000'001];
ll dp[1 << 20];
int par[1 << 20];

int binsf(ll rozn, const int &n) {
    // cerr << "bins " << rozn << endl;
    // droptop(i, 0, n)
    // {
    //     cerr << dif[i] << " ";
    // }
    // cerr << endl;
    //
    int l = 0, r = n;
    int tst = 5;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        // cerr << l << " " << r << " " << mid << endl;
        // int mid = (l + r) >> 1;
        if (dif[mid] > rozn)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int f() {
    int n, k;
    cin >> n >> k;
    wec.resize(n), pref.resize(k);

    droptop(i, 0, n)
    {
        int p;
        ll c, t;
        cin >> p >> c >> t;
        wec[i] = {p - 1, i + 1, c, t};
    }
    hotbox(wec);

    ll sum = 0;
    droptop(i, 0, n)
    {
        auto [p, id, c, t] = wec[i];

        sum += c;
        dif[i] = max(i ? dif[i - 1] : (ll)0, sum - t);

        pair<ll, int> cur = {c, id};
        if (not pref[p].empty() and pref[p].back().first >= cur.first)
            cur = pref[p].back();
        pref[p].pb(cur), pos[p].pb(i);
    }

    droptop(i, 1, (1 << k))
    {
        dp[i] = -1;
    }
    droptop(i, 0, (1 << k))
    {
        if (dp[i] < 0)
            continue;
        ll cur = binsf(dp[i], n);
        if (cur == n) {
            int mask = i;
            vector<int> res(k, -1);
            while (mask) {
                int j = par[mask], lst = mask ^ (1 << j);
                int idx = upper_bound(pos[j].begin(), pos[j].end(), binsf(dp[lst], n)) - pos[j].begin();
                res[j] = pref[j][idx - 1].second, mask = lst;
            }
            cout << "TAK\n";
            droptop(i, 0, k)
            {
                cout << res[i] << "\n";
            }
            return 0;
        } else {
            droptop(j, 0, k)
            {
                if (i & (1 << j))
                    continue;
                int maks = upper_bound(pos[j].begin(), pos[j].end(), cur) - pos[j].begin();
                if (not maks)
                    continue;
                int idx = i | (1 << j);
                ll war = dp[i] + pref[j][maks - 1].first;
                if (war > dp[idx])
                    dp[idx] = war, par[idx] = j;
            }
        }
    }
    cout << "NIE";
    return 0;
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
