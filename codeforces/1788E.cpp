/*
Now playing:
Offset - Every Night (feat. Don Toliver) [Every Night (feat. Don Toliver)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define int ll
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back

int dp[200'001];
int tab[200'001];
ll pref[200'001];
vector<ll> prefs;

const int base = 200'001;
int tree[base << 2];

void add(int w, int l, int r, int idx, int war) {
    if (l == r) {
        tree[w] = max(tree[w], war);
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (idx <= mid)
        add(w << 1, l, mid, idx, war);
    else
        add(w << 1 | 1, mid + 1, r, idx, war);
    tree[w] = max(tree[w << 1], tree[w << 1 | 1]);
}

int query(int w, int l, int r, int a, int b) {
    if (r < a or b < l)
        return -2e18;
    if (a <= l and r <= b)
        return tree[w];
    int mid = l + ((r - l) >> 1);
    return max(query(w << 1, l, mid, a, b), query(w << 1 | 1, mid + 1, r, a, b));
}

int getf(ll x) {
    return lower_bound(prefs.begin(), prefs.end(), x) - prefs.begin() + 1;
}

int f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    prefs.reserve(n + 1);
    prefs.pb(0);
    droptop(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + (ll)tab[i], prefs.pb(pref[i]);
    }

    hotbox(prefs);
    prefs.erase(unique(prefs.begin(), prefs.end()), prefs.end());
    const int m = prefs.size();

    droptop(i, 0, (base << 2))
    {
        tree[i] = -2e18;
    }
    int pos = getf(false);
    add(1, 1, m, pos, false);
    droptop(i, 1, n + 1)
    {
        int pos = getf(pref[i]), cur = query(1, 1, m, 1, pos);
        dp[i] = dp[i - 1];
        if (cur > -2e18)
            dp[i] = max(dp[i], cur + i);
        add(1, 1, m, pos, dp[i] - i);
    }
    return dp[n];
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
