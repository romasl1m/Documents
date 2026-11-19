/*
Now playing:
Pop Smoke - Invincible [Meet The Woo 2 (Deluxe)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
int n;
struct dp {
    int l, r, range;
};
dp dfs(int w, const vector<vector<pair<int, int>>> &wec, int mid, int p = -1, int pdir = 0) {
    int l = 1, r = mid, range = 0;
    for (auto [ss, dir] : wec[w]) {
        if (ss == p)
            continue;
        auto [a, b, cur] = dfs(ss, wec, mid, w, dir);
        if (a > b)
            return {1, 0};

        int mini = a;
        int maks = b;
        if (cur == b)
            maks--;
        if (cur == a)
            mini++;

        if (dir == 1) {
            r = min(r, maks - 1);
        } else if (dir == 2) {
            l = max(l, mini + 1);
        } else {
            if (mini == maks) {
                int nope = mini;
                if (nope == l)
                    l++;
                else if (nope == r)
                    r--;
                else if (l < nope and nope < r) {
                    if (range != 0 and range != nope)
                        return {1, 0, 0};
                    range = nope;
                }
            }
        }
    }
    if (l > r)
        return {1, 0, 0};
    if (range == l)
        l++, range = 0;
    else if (range == r)
        r--, range = 0;
    if (l > r or (l == r and l == range))
        return {1, 0, 0};

    return {l, r, range};
    // return {l, r};
}
bool check(int mid, const vector<vector<pair<int, int>>> &wec, vector<pair<int, int>> &dp) {
    auto [l, r, cur] = dfs(1, wec, mid);
    return l <= r;
    // cout << "___DP DEBUG___\n";
    // droptop(1, n + 1)
    // {
    //     cout << dp[i].first << " " << dp[i].second << endl;
    // }
}
int main() {
    raindrop;
    int t;
    cin >> t;
    cookie(t)
    {
        cin >> n;
        vector<vector<pair<int, int>>> wec(n + 1);
        vector<pair<int, int>> dp(n + 1, {1, n});
        droptop(1, n)
        {
            int a, b;
            bool c;
            cin >> a >> b >> c;
            if (c) {
                wec[a].pb({b, 1});
                wec[b].pb({a, 2});
            } else {
                wec[a].pb({b, 0});
                wec[b].pb({a, 0});
            }
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (not check(mid, wec, dp)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << r << "\n";
    }
}
