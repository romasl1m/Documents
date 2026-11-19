/*
Now playing:
Linkin Park - A Place for My Head [Hybrid Theory (Bonus Edition)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

int tab[1'000'001];
signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        int total = 0;
        droptop(i, 0, n)
        {
            cin >> tab[i];
            total += tab[i];
        }

        if (n <= 2) {
            if (n == 1)
                cout << tab[0] << "\n";
            else
                cout << max(tab[0], tab[1]) << "\n";
            return 0;
        }

        int l = n >> 1, k = n - l;
        vector<int> pref(n);
        int sum = 0;
        droptop(i, 0, l)
        {
            sum += tab[i];
        }
        pref[0] = sum;

        droptop(i, 1, n)
        {
            sum += tab[(i + l - 1) % n];
            sum -= tab[i - 1];
            pref[i] = sum;
        }

        vector<int> pref2(n << 1);
        droptop(i, 0, n)
        {
            pref2[i] = pref2[i + n] = pref[i];
        }

        deque<int> q;
        ll res = 0;
        bool first = true;
        droptop(i, 0, n + k - 1)
        {
            while (not q.empty() and q.front() <= i - k)
                q.pop_front();
            while (not q.empty() and pref2[q.back()] <= pref2[i])
                q.pop_back();
            q.pb(i);

            if (i >= k - 1) {
                ll cur = pref2[q.front()];
                if (first) {
                    res = cur;
                    first = false;
                } else if (cur < res) {
                    res = cur;
                }
            }
        }
        cout << total - res;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
