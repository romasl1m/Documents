/*
Now playing:
Artemas - eat me alive [LOVERCORE]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int tab[10'001], wec[10'001];
vector<int> dp, curdp;

void f() {
    int n, m;
    cin >> n >> m;
    dp.resize(m), curdp.resize(m);
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    droptop(i, 0, m)
    {
        cin >> wec[i];
    }

    int res = m;
    droptop(i, 0, m)
    {
        int cur = 0;
        droptop(j, 0, m)
        {
            if (tab[j] != wec[(i + j) % m])
                cur++;
        }
        dp[i] = cur;
        res = min(res, cur);
    }

    droptop(i, 0, n - m)
    {
        droptop(j, 0, m)
        {
            int last = (j + m - 1) % m;
            curdp[j] = dp[last];

            if (wec[last] != tab[i])
                curdp[j]--;
            if (wec[(j + m - 1) % m] != tab[i + m])
                curdp[j]++;
        }

        droptop(j, 0, m)
        {
            res = min(res, curdp[j]);
        }
        // dp = move(curdp);
        swap(dp, curdp);
    }
    cout << res;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
