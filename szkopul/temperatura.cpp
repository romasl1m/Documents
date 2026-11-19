/*
Now playing:
Lil Peep - high school [LIL PEEP; PART ONE]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

pair<int, int> tab[1'000'001];
int f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        cin >> tab[i].first >> tab[i].second;
    }

    deque<int> q;
    int res = 1, l = 0;
    droptop(r, 0, n)
    {
        while (not q.empty() and tab[q.back()].first <= tab[r].first)
            q.pop_back();
        // if (q.empty() or tab[r].second >= tab[q.front()].first)
        q.pb(r);
        while (tab[q.front()].first > tab[r].second) {
            l++;
            if (q.front() < l)
                q.pop_front();
        }
        // cerr << l << " " << r << endl;
        res = max(r - l + 1, res);
    }

    return res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
