/*
Now playing:
Young Thug - Chanel (Go Get It) [feat. Gunna and Lil Baby] [Slime Language]
*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

ll lastk = 0;
vector<int> last;

vector<int> get(ll k) {
    if (lastk == k)
        return last;

    cout << "? " << k << endl;
    int q;
    cin >> q;
    if (q == 0) {
        lastk = k;
        return last = {};
    }

    vector<int> cur(q);
    droptop(i, 0, q)
    {
        cin >> cur[i];
    }
    lastk = k, last = cur;
    return cur;
}

ll dfs(int w, ll startk, vector<int> &pref, vector<ll> &dp, vector<vector<int>> &wec) {
    if (dp[w] >= 0)
        return dp[w];
    ll path = 1, nxt = startk + 1;

    while (true) {
        vector<int> sciezka = get(nxt);
        bool ok = true;
        if (sciezka.size() <= pref.size()) {
            ok = false;
        } else {
            droptop(j, 0, pref.size())
            {
                if (pref[j] != sciezka[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (not ok)
            break;

        int ss = sciezka[pref.size()];
        wec[w].pb(ss);

        pref.pb(ss);
        ll cur = dfs(ss, nxt, pref, dp, wec);
        pref.pop_back();

        path += cur, nxt += cur;
    }
    return dp[w] = path;
}

void f() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    vector<vector<int>> wec(n + 1);

    ll cur = 1;
    droptop(i, 1, n + 1)
    {
        vector<int> pref = {i};
        cur += dfs(i, cur, pref, dp, wec);
    }

    int m = 0;
    droptop(i, 1, n + 1)
    {
        m += wec[i].size();
    }
    cout << "! " << m << endl;
    droptop(i, 1, n + 1)
    {
        if (wec[i].empty())
            continue;
        for (int ss : wec[i]) {
            cout << i << " " << ss << endl;
        }
    }
}
signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        lastk = 0;
        last.clear();
        f();
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
