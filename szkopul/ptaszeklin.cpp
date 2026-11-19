/*
Now playing:
KUR - Grab Your Popcorn - Remix [Grab Your Popcorn (Remix)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <deque>
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

int tab[1'000'001];
int dp[1'000'001];

void f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    int q1;
    cin >> q1;
    // cerr << "q1 " << q1 << endl;
    while (q1--) {
        int cur;
        cin >> cur;

        deque<int> q = {0};
        droptop(i, 1, n)
        {
            while (not q.empty() and i - q.front() > cur)
                q.pop_front();
            int best = q.front();
            dp[i] = dp[best] + (tab[best] <= tab[i]);

            while (not q.empty()) {
                int last = q.back();
                if (dp[last] > dp[i] or (dp[last] == dp[i] and tab[last] < tab[i]))
                    q.pop_back();
                else
                    break;
            }
            q.pb(i);
        }
        cout << dp[n - 1] << "\n";
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        // cout << "\n";
    }
    return 0;
}
