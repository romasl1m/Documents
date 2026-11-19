/*
Now playing:
Bring Me The Horizon - LosT [LosT]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    if (n <= 3)
        return 0;

    int leaves = 0;
    droptop(i, 1, n + 1)
    {
        if (wec[i].size() == 1)
            leaves++;
    }

    int cheapest = 0;
    droptop(i, 1, n + 1)
    {
        int cur = 0;
        for (int ss : wec[i])
            if (wec[ss].size() == 1)
                cur++;
        cheapest = max(cheapest, cur);
    }

    return leaves - cheapest;
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            cout << f() << "\n";
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
