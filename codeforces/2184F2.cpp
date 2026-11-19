/*
Now playing:
Sentino - MR. OFFICER [KING SENTO PROLOG]
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

vector<bool> dp[200'001];
// void f(bool (&l)[3], bool (&r)[3], bool (&cur)[3]) {
void f(vector<bool> &l, vector<bool> &r, vector<bool> &cur) {
    droptop(i, 0, 3)
    {
        if (not l[i])
            continue;
        droptop(j, 0, 3)
        {
            if (not r[j])
                continue;
            cur[(i + j) % 3] = true;
        }
    }
}

void dfs(const int &w, const int &p, const vector<vector<int>> &wec) {
    vector<int> children;
    dp[w].resize(3);
    for (const int &ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, wec);
        children.pb(ss);
    }

    if (not children.empty()) {
        dp[w][0] = true;
        for (const int &ss : children) {
            vector<bool> cur(3, false);
            f(dp[w], dp[ss], cur);
            dp[w] = move(cur);

            // bool cur[3] = {false, false, false};
            // f(dp[w], dp[ss], cur);
            // dp[w][0] = cur[0], dp[w][1] = cur[1], dp[w][2] = cur[2];
        }
    }
    dp[w][1] = true;
}

void f() {
    int n;
    cin >> n;
    vector<vector<int>> wec(n + 1);
    droptop(i, 1, n + 1)
    {
        dp[i].clear();
    }
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }
    dfs(1, 0, wec);
    cout << (dp[1][0] ? "YES\n" : "NO\n");
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
