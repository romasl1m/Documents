#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
const int mod = 1e9 + 7;

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int m, n;
        cin >> m >> n;
        vector<pair<int, int>> wec(n);
        droptop(0, n)
        {
            cin >> wec[i].first >> wec[i].second;
            wec[i].second--;
        }
        hotbox(wec);
        int last = -1, res = 0;
        vector<int> stations;
        for (int i = 0; i < n; i++) {
            if (last <= wec[i].first) {
                res++, last = wec[i].second;
                stations.pb(last);
            }
        }
        if (res == 0) {
            cout << "0 1\n";
            continue;
        }
        vector<int> pos(n << 1);
        droptop(0, n)
        {
            pos[i] = wec[i].first, pos[i << 1] = wec[i].second;
        }
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());

        auto get = [&](int w) {
            return lower_bound(pos.begin(), pos.end(), w) - pos.begin() + 1;
        };

        int k = pos.size();
        vector<int> minr(k + 1, k + 2), maksl(k + 1, 0);
        // max start of a passager in i and min end
        droptop(0, n)
        {
            int l = get(wec[i].first), r = get(wec[i].second);
            minr[l] = min(minr[l], r);
            maksl[r] = max(maksl[r], l);
        }
        for (int i = k; i >= 1; i--) {
            minr[i] = min(minr[i], minr[i + 1]);
        }
        droptop(1, k + 1)
        {
            maksl[i] = max(maksl[i], maksl[i - 1]);
        }

        // DP
        vector<pair<int, long long>> dp(k + 2, {k + 2, 0});
        vector<long long> pref_ways(k + 2, 0);
        dp[0] = {0, 1};

        auto sposob = [&](int l, int r, int res) {
            if (l > r)
                return 0LL;
            long long cur = 0;
            droptop(l, r + 1)
            {
                if (dp[i].first == res) {
                    cur = (cur + dp[i].second) % mod;
                }
            }
            return cur;
        };

        int left = 0;
        droptop(1, k + 1)
        {
            int curl = maksl[i - 1];
            int minlast = k + 2;
            for (int j = curl; j < i; j++) {
                minlast = min(minlast, dp[j].first);
            }
            if (minlast <= k) {
                dp[i].first = minlast + 1;
                dp[i].second = sposob(curl, i, minlast);
            }
        }

        int lastl = maksl[k];
        long long ways = 0;
        droptop(lastl, k + 1)
        {
            if (dp[i].first == res) {
                ways = (ways + dp[i].second) % mod;
            }
        }
        cout << res << ways << "\n";
    }
}
