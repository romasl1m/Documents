/*
Now playing:
Juice WRLD - Cavalier [The Pre-Party (Extended)]
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

struct s {
    int res, used, sum, dep;
};

s dfs(int w, int p, const vector<vector<int>> &wec, const vector<int> &tab, vector<s> &dp) {
    s cur = {0, 0, tab[w], 0};
    int maksdep = 0, secdep = 0, dif = 0;

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        s nxt = dfs(ss, w, wec, tab, dp);

        if (nxt.dep + 1 >= maksdep)
            secdep = maksdep, maksdep = nxt.dep + 1;
        else if (nxt.dep + 1 > secdep)
            secdep = nxt.dep + 1;

        dif = max(dif, nxt.used - nxt.res);

        cur.res += nxt.res + nxt.sum,
            cur.used += nxt.res + nxt.sum,
            cur.sum += nxt.sum;
    }

    cur.used += dif,
        cur.dep = maksdep;

    for (int ss : wec[w]) {
        if (ss == p)
            continue;

        int otherdep = (dp[ss].dep + 1 == maksdep ? secdep : maksdep);
        cur.used = max(cur.used, cur.res + otherdep * dp[ss].sum);
    }
    dp[w] = cur;
    return cur;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    vector<int> tab(n + 1);

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

    vector<s> dp(n + 1);
    dfs(1, 0, wec, tab, dp);

    droptop(i, 1, n + 1)
    {
        cout << dp[i].used << " ";
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
