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
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

int dp[100'001][20], tab[100'001], cnt[100'001];
int lg = 1, rg = 0;
ll cur = 0;

ll costf(int l, int r) {
    while (r > rg)
        rg++, cur += cnt[tab[rg]]++;
    while (l < lg)
        lg--, cur += cnt[tab[lg]]++;
    while (r < rg)
        cur -= --cnt[tab[rg]], rg--;
    while (l > lg)
        cur -= --cnt[tab[lg]], lg++;
    return cur;
}

void dc(int w, int l, int r, int a, int b) {
    if (l > r)
        return;
    int mid = l + ((r - l) >> 1);
    pair<ll, int> best = {2e18, -1};

    droptop(i, a, min(mid - 1, b) + 1)
    {
        ll cost = dp[i][w - 1] + costf(i + 1, mid);
        if (best.first > cost)
            best = {cost, i};
    }
    dp[mid][w] = best.first;
    if (best.second == -1)
        best.second = a;

    dc(w, l, mid - 1, a, best.second), dc(w, mid + 1, r, best.second, b);
}

int f() {
    int n, k;
    cin >> n >> k;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }

    droptop(i, 1, n + 1)
    {
        dp[i][1] = costf(1, i);
    }
    droptop(i, 2, k + 1)
    {
        dc(i, 1, n, 1, n);
    }

    // droptop(i, 0, k)
    // {
    //     cout << "k " << i << ": ";
    //     droptop(j, 0, n)
    //     {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][k];
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
