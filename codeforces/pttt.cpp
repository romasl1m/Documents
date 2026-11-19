/*
Now playing:
J. Cole - Poor Thang [The Fall-Off]
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

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        vector<ll> tab(n);
        droptop(0, n)
        {
            cin >> tab[i];
        }

        droptop(0, n)
        {

            vector<ll> maks(n, 2e18);
            vector<int> cur(n);
            cur[i] = 0;
            for (int j = 1; j < n; j++) {
                int w = (i + j) % n, last = (i + j - 1 + n) % n;
                cur[w] = tab[last];
            }
            maks[i] = 0;
            for (int j = 0; j < (n << 1); j++) {
                int w = (i + j) % n;
                int nxt = (w + 1) % n;
                maks[nxt] = min(maks[nxt], max(maks[w], tab[w]));
            }
            for (int j = 0; j < (n << 1); j++) {
                int w = ((i - j) % n + n) % n;
                int last = (w - 1 + n) % n;
                maks[last] = min(maks[last], max(maks[w], tab[last]));
            }
            ll res = 0;
            for (int ss : maks) {
                res += ss;
            }
            cout << res << " ";
        }
        cout << "\n";
    }
}
