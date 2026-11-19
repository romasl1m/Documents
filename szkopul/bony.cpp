/*
Now playing:
Juice WRLD - Not Enough [Fighting Demons (Deluxe)]
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
#define int unsigned long long
int tab[1'000'001];
bool bon[1'000'001];
int last[1'000'001];
bool wiz[1'000'001];
vector<int> res;

signed main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int m;
        cin >> m;
        int maks = 0;
        droptop(0, m)
        {
            cin >> tab[i];
            maks = max(maks, tab[i]);
            bon[tab[i]] = true;
        }
        int n;
        cin >> n;
        int total = 0;

        droptop(1, n + 1)
        {
            int p;
            cin >> p;
            if (last[p] == 0)
                last[p] = p;
            int cur = last[p];
            int num = 0;
            for (; last[p] <= maks and num < p; last[p] += p) {
                if (not wiz[last[p]]) {
                    wiz[last[p]] = true;
                    num++;
                    if (bon[last[p]]) {
                        res.pb(total + num);
                    }
                }
            }
            total += p;
        }
    }
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << "\n";
    }
}
