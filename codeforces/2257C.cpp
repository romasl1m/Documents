/*
Now playing:
Bring Me The Horizon - Kool-Aid [POST HUMAN: NeX GEn]
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

void dfs(int w, int p, const vector<vector<int>> &wec, vector<int> &dep) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w, wec, dep);
    }
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> dep(n + 1);
    droptop(i, 2, n + 1)
    {
        int x;
        cin >> x;
        wec[x].pb(i);
    }

    int m;
    cin >> m;

    if (m == 0) {
        cout << "0\n";
        return;
    }
    vector<int> tab(m);
    bool skip = false;

    droptop(i, 0, m)
    {
        int x;
        cin >> x;
        tab[i] = x;
        if (x == 1)
            skip = true;
    }

    dfs(1, 0, wec, dep);

    int cur = 0;
    cout << m - 1 << " ";

    if (skip) {
        cur = 1;
    } else {
        int t = tab[0];
        droptop(i, 1, m)
        {
            if (dep[tab[i]] < dep[t])
                t = tab[i];
        }
        cur = t;
    }

    // cerr << "cur " << cur << endl;
    droptop(i, 0, m)
    {
        if (tab[i] == cur)
            continue;
        cout << tab[i] << " ";
    }
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            f();
            cout << "\n";
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
