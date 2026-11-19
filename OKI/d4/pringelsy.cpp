/*
Now playing:

*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// int pref[350][100005];
int res[100'001];
vector<pair<int, int>> query[350];
int pref[100'001];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, q;
        cin >> n >> q;

        while (q--) {
            int a, l, d;
            cin >> a >> l >> d;

            if (l <= 0)
                continue;
            if (d == 0) {
                if (a <= n)
                    res[a] += l;
                continue;
            }

            if (d >= 350) {
                droptop(i, 0, l)
                {
                    int idx = a + i * d;
                    if (idx <= n)
                        res[idx]++;
                    else
                        break;
                }
            } else {
                query[d].pb({a, l});
                // pref[d][a]++;
                // long long endidx = (long long)a + (long long)l * d;
                // if (endidx <= n) {
                //     pref[d][endidx]--;
                // }
            }
        }

        droptop(i, 1, 350)
        {
            if (query[i].empty())
                continue;

            for (const auto [a, l] : query[i]) {
                pref[a]++;
                ll endidx = (ll)a + (ll)l * i;
                if (endidx <= n + 1)
                    pref[endidx]--;
            }

            droptop(j, 1, n + 1)
            {
                if (j >= i) {
                    pref[j] += pref[j - i];
                }
                res[j] += pref[j];
            }
            droptop(i, 0, n + 2)
            {
                pref[i] = 0;
            }
        }

        droptop(i, 1, n + 1)
        {
            cout << res[i] << " ";
        }
    }
    return 0;
}
