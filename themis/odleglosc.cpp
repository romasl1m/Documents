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

vector<int> wec[50'001];
ll dp[50'001][501];

ll res = 0;

void dfs(int w, int p, const int &k) {
    dp[w][0] = 1;
    for (const int &ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, k);

        droptop(i, 0, k)
        {
            res += dp[w][i] * dp[ss][k - i - 1];
        }

        droptop(i, 0, k)
        {
            dp[w][i + 1] += dp[ss][i];
        }
    }
}
void f() {
    int n, k;
    cin >> n >> k;
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }

    dfs(1, 0, k);
    cout << res;
}

int main() {
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
