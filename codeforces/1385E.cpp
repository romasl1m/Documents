/*
Now playing:
Lady Pank - Zamki na piasku [Lady Pank]
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

bool wiz[200'001];
void dfs(int w, const vector<vector<pair<int, int>>> &wec, vector<int> &topo) {
    wiz[w] = true;
    for (auto [ss, c] : wec[w]) {
        if (not c or wiz[ss])
            continue;
        dfs(ss, wec, topo);
    }
    topo.pb(w);
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 1, n + 1)
    {
        wiz[i] = false;
    }
    vector<vector<pair<int, int>>> wec(n + 1);
    vector<pair<int, int>> roads;
    roads.reserve(m);
    droptop(i, 0, m)
    {
        int a, b, c;
        cin >> c >> a >> b;

        if (c)
            wec[a].pb({b, c});
        // cerr << a << " " << b << "alr\n";
        roads.pb({a, b});
        // wec[a].pb({b, c});
        // if (c)
        //     wec[b].pb({a, c});
    }

    vector<int> topo, cur(n + 1);
    topo.reserve(n);
    droptop(i, 1, n + 1)
    {
        if (wiz[i])
            continue;
        dfs(i, wec, topo);
    }

    if (topo.size() < n) {
        cout << "NO";
        return;
    }
    // cookie(i, n - 1, 0)
    // {
    //     cur[topo[i]] = i;
    // }
    reverse(topo.begin(), topo.end());
    droptop(i, 0, n)
    {
        cur[topo[i]] = i;
    }

    int ok = true;
    droptop(i, 1, n + 1)
    {
        for (auto [ss, c] : wec[i])
            if (cur[ss] < cur[i]) {
                // cerr << "wrong between " << i << " " << ss << endl;
                ok = false;
                i = n + 2;
                break;
            }
    }

    if (not ok) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    droptop(i, 0, m)
    {
        auto &[a, b] = roads[i];

        if (cur[a] < cur[b])
            cout << a << " " << b << "\n";
        else
            cout << b << " " << a << "\n";
    }
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
