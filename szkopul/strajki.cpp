/*
Now playing:

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

vector<int> wec[500'001];
int par[500'001];
int bannedch[500'001];
bool blocked[500'001];

int check(int w, int res) {
    if (w < 0) {
        w *= -1, blocked[w] = false;
        if (par[w] > 0 and blocked[par[w]])
            res++;
        res -= wec[w].size() - 1 - bannedch[w];
        bannedch[par[w]]--;
    } else {
        blocked[w] = true;
        if (par[w] > 0 and blocked[par[w]])
            res--;
        res += wec[w].size() - 1 - bannedch[w];
        bannedch[par[w]]++;
    }
    return res;
}
void dfs(int w, int p) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        par[ss] = w;
        dfs(ss, w);
    }
}

void f() {
    int n;
    cin >> n;
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0);
    int res = 1;
    int m;
    cin >> m;
    while (m--) {
        int w;
        cin >> w;
        res = check(w, res);
        cout << res << "\n";
    }
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
