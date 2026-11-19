/*
Now playing:
Linkin Park - Wastelands [The Hunting Party]
*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll tab[1'000'001];
bool ok[1'000'002];
// unordered_map<int, ll> dp[1'000'001];
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        int need = (n >> 1), mod = (need << 1);

        vector<int> prev(n + 2), nxt(n + 2);

        droptop(i, 1, n + 1)
        {
            cin >> tab[i];
            nxt[i] = i + 1;
            prev[i] = i - 1;
            ok[i] = true;
        }
        tab[0] = 1e18, tab[n + 1] = 1e18, prev[0] = -1, nxt[0] = 1, prev[n + 1] = n, nxt[n + 1] = -1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        droptop(i, 1, n + 1)
        {
            q.push({tab[i], i});
        }

        ll res = 0;
        int cur = 0;
        while (not q.empty() and cur < need) {
            auto [war, w] = q.top();
            q.pop();
            if (not ok[w])
                continue;
            res += war, cur++;

            int l = prev[w], r = nxt[w];
            ok[l] = ok[r] = false;

            tab[w] = tab[l] + tab[r] - tab[w];
            prev[w] = prev[l];
            if (prev[l] != -1)
                nxt[prev[l]] = w;
            nxt[w] = nxt[r];
            if (nxt[r] != -1) {
                prev[nxt[r]] = w;
            }

            q.push({tab[w], w});
        }

        cout << res;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
