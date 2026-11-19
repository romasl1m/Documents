/*
Now playing:
Travis Scott - Nightcrawler (feat. Swae Lee and Chief Keef) [Rodeo]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(long long a, long long b) {
    return a > b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> tab(n + 1);
        vector<ll> par(n + 1);

        droptop(i, 1, n + 1)
        {
            cin >> tab[i];
        }
        droptop(i, 2, n + 1)
        {
            cin >> par[i];
        }

        vector<priority_queue<ll, vector<ll>, greater<ll>>> wec(n + 1);
        vector<ll> cur;

        for (int i = n; i >= 1; i--) {
            if (wec[i].empty()) {
                wec[i].push(tab[i]);
            } else {
                ll maks = wec[i].top();
                cur.pb(min(maks, tab[i]));
                wec[i].pop(), wec[i].push(max(maks, tab[i]));
            }

            if (i > 1) {
                // psh
                int p = par[i];
                if (wec[i].size() > wec[p].size())
                    swap(wec[i], wec[p]);

                while (not wec[i].empty()) {
                    wec[p].push(wec[i].top()), wec[i].pop();
                }
            }
        }

        ll total = 0;
        int root = wec[1].size();
        while (not wec[1].empty())
            total += wec[1].top(), wec[1].pop();

        vector<ll> res(n + 1, -1);
        res[root] = total;

        hotbox(cur);
        droptop(i, 0, cur.size())
        {
            total += cur[i];
            res[root + i + 1] = total;
        }
        droptop(i, 1, n + 1)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
// was forces 2do ts cause of the when the night crawls
