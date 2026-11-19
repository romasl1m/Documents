/*
Now playing:
Linkin Park - Burning in the Skies [A Thousand Suns]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int long long
struct ulm {
    int p, q;
};
struct comp {
    bool compf(const pair<ulm, ulm> &a, const pair<ulm, ulm> &b) {
        return
    }
};

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
ulm res[1'000'001];
signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, x, z;
        cin >> n >> x >> z;
        int last = 0;
        priority_queue<pair<ulm, ulm>, vector<pair<ulm, ulm>>, comp> q;
        droptop(i, 0, n)
        {
            int cur;
            cin >> cur;
            q.push({last, cur});
            last = cur;
        }
        q.push({last, x});

        droptop(i, 1, 1'000'001)
        {
            auto [a, b] = q.top();
            q.pop();
            int mid = a + ((b - a) >> 1);
            res[i] = mid;
            q.push({a, mid}), q.push({mid, b});
        }

        while (z--) {
            int cur;
            cin >> cur;
            cout << res[cur] << "\n";
        }
    }
}
