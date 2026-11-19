/*
Now playing:
Linkin Park - Forgotten [Hybrid Theory (Bonus Edition)]
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

int dfs(const int &w, const int &p, const vector<vector<int>> &wec, bool &ok) {
    vector<int> children;
    int cnt = 0;

    for (const int &ss : wec[w]) {
        if (ss == p)
            continue;
        cnt++;
        const int &cur = dfs(ss, w, wec, ok);
        if (cur > 0)
            children.pb(cur);
    }

    if (children.size() > 1) {
        ok = true;
        return false;
    }

    const int &cur = (cnt == 0 ? 0 : (cnt + 2) % 3);
    vector<int> ord;

    if (cur)
        ord.pb(cur);
    if (not children.empty())
        ord.pb(children.front());
    if (ord.size() == 2 and ord.front() + ord.back() != 3) {
        ok = true;
        return false;
    }
    if (ord.size())
        return ord.front();
    return false;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    // int leaves = 0;
    // droptop(i, 1, n + 1)
    // {
    //     if (wec[i].size() == 1)
    //         leaves++;
    // }
    //
    // if (leaves % 3 == 0) {
    //     cout << "YES\n";
    //     return;
    // }
    // if (leaves < 3) {
    //     cout << "NO\n";
    //     return;
    // }
    bool ok = false;
    cout << ((dfs(1, 0, wec, ok) == 2 or ok) ? "YES\n" : "NO\n");
}

int main() {
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
