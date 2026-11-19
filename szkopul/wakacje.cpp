/*
Now playing:
Playboi Carti - SOUTH ATLANTA BABY [MUSIC]
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

int tab[1'000'001];
vector<int> wec[1'000'001];
int par[1'000'001][2];
int dp[1'000'001][2];
bool wiz[1'000'001];

int maks = -1, best = 1;
bool beh = false, type = false;

int behw[1'000'001][2], behss[1'000'001][2];

void upd(int w, int war, int &w1, int &w2, int &ss1, int &ss2) {
    if (war > ss1)
        ss2 = ss1, w2 = w1, ss1 = war, w1 = w;
    else if (war > ss2)
        ss2 = war, w2 = w;
}

void dfs(int w, int p) {
    dp[w][1] = tab[w];
    dp[w][0] = -1e9;
    par[w][1] = 0;
    par[w][0] = 0;

    int sum = 0;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        sum += tab[ss];
    }

    // int cur1 = -1e9, cur0 = -1e9;
    // int p1 = 0, p0 = 0;

    int w1w = 0, w2w = 0, ss1w = -1e9, ss2w = -1e9,
        w1ss = 0, w2ss = 0, ss1ss = -1e9, ss2ss = -1e9;

    for (int ss : wec[w]) {
        if (ss == p)
            continue;

        if (dp[ss][0] > dp[w][1] - tab[w]) {
            dp[w][1] = tab[w] + dp[ss][0], par[w][1] = ss;
        }
        upd(ss, dp[ss][0], w1w, w2w, ss1w, ss2w);

        int dif = dp[ss][1] - tab[ss];
        upd(ss, dif, w1ss, w2ss, ss1ss, ss2ss);
    }
    if (w1ss != 0)
        dp[w][0] = sum + ss1ss, par[w][0] = w1ss;

    behw[w][1] = w1w, behss[w][1] = w2w,
    behw[w][0] = w1ss, behss[w][0] = w2ss;

    if (dp[w][1] > maks) {
        maks = dp[w][1];
        best = w;
        beh = false;
    }

    if (ss1w != 0 and ss2w != 0) {
        int cur = tab[w] + ss1w + ss2w;
        if (cur > maks) {
            maks = cur;
            best = w;
            beh = true, type = true;
        }
    }

    if (w1ss != 0 and w2ss != 0) {
        int cur = sum + ss1ss + ss2ss;
        if (cur > maks) {
            maks = cur;
            best = w;
            beh = true, type = false;
        }
    }
}

void get(int w, int p, bool col, vector<int> &path) {
    if (col) {
        path.pb(w);
        int nxt = par[w][1];
        if (nxt != 0)
            get(nxt, w, false, path);
    } else {
        int nxt = par[w][0];
        for (int ss : wec[w]) {
            if (ss == p or ss == nxt)
                continue;
            path.pb(w), path.pb(ss);
        }

        if (nxt != 0) {
            path.pb(w);
            get(nxt, w, true, path);
        }
    }
}

void f() {
    int n;
    cin >> n;
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

    dfs(1, 0);
    vector<int> path;

    if (not beh)
        get(best, 0, true, path);
    else {
        int w = behw[best][type ? 1 : 0], ss = behss[best][type ? 1 : 0];

        vector<int> path1, path2;
        get(w, best, not type, path1), get(ss, best, not type, path2);

        reverse(path1.begin(), path1.end());
        for (int x : path1)
            path.pb(x);

        if (type)
            path.pb(best);
        else {
            path.pb(best);
            for (int ss1 : wec[best]) {
                if (ss1 == w or ss1 == ss)
                    continue;
                path.pb(ss1);
                path.pb(best);
            }
        }

        for (int x : path2)
            path.pb(x);
    }

    cout << maks << "\n"
         << ((path.size() + 1) >> 1) << "\n";
    droptop(i, 0, path.size())
    {
        cout << path[i] << " ";
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
