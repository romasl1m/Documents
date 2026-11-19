/*
Now playing:
Linkin Park - All for Nothing (feat. Page Hamilton) [The Hunting Party]
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

int f() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> pref, ans, wec;
    wec.reserve(n), pref.reserve(n), ans.reserve(n);

    droptop(i, 0, n)
    {
        int prw = pref.empty() ? 0 : pref.back();
        wec.pb(i + 1), pref.pb(prw + (s[i] == 'c' ? -k : 1));

        if ((int)wec.size() >= k + 1) {
            int siz = wec.size(), cur = pref.back(), idx = siz - k - 2, lst = (idx < 0) ? 0 : pref[idx];

            if (cur == lst) {
                vector<int> res;
                droptop(j, 0, k + 1)
                {
                    ans.pb(wec.back()), wec.pop_back(), pref.pop_back();
                }
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i -= (k + 1)) {
        droptop(j, 0, k + 1)
        {
            cout << ans[i - j] << " ";
        }
        cout << "\n";
    }
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
