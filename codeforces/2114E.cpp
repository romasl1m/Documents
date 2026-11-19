/*
Now playing:
Trippie Redd - KingofTheWorld [#NDA]
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
#define int ll

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &dpmin, vector<int> &dpmaks, const vector<int> &tab) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dpmin[ss] = min(tab[ss], tab[ss] - dpmaks[w]),
        dpmaks[ss] = max(tab[ss], tab[ss] - dpmin[w]);

        dfs(ss, w, wec, dpmin, dpmaks, tab);
    }
}

void f() {
    int n;
    cin >> n;
    vector<int> tab(n + 1);
    vector<vector<int>> wec(n + 1);
    vector<int> dpmin(n + 1), dpmaks(n + 1);

    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dpmin[1] = dpmaks[1] = tab[1];
    dfs(1, 0, wec, dpmin, dpmaks, tab);

    droptop(i, 1, n + 1)
    {
        cout << dpmaks[i] << " ";
    }
    cout << "\n";
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
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
