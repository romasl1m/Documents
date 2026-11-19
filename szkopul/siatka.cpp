/*
Now playing:
Huncho Jack - Modern Slavery [Huncho Jack, Jack Huncho]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[1'000'001];
int sub[1'000'001];
int par[1'000'001];
bool wiz[1'000'001];

void dfs(int w, int p = -1) {
    sub[w] = 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w);
        sub[w] += sub[ss];
    }
}
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        droptop(i, 1, n + 1)
        {
            wec[i].clear(), sub[i] = 1, wiz[i] = false, par[i] = 0;
        }
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            wec[b].pb(a);
        }

        vector<int> ord;
        ord.reserve(n + 1);
        queue<int> q;
        q.push(1);
        wiz[1] = true;
        while (not q.empty()) {
            int w = q.front();
            q.pop();
            ord.pb(w);
            for (int ss : wec[w]) {
                if (wiz[ss])
                    continue;
                q.push(ss);
                par[ss] = w, wiz[ss] = true;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int w = ord[i];
            if (par[w] == 0)
                continue;
            sub[par[w]] += sub[w];
        }

        droptop(i, 1, n + 1)
        {
            wiz[i] = false;
        }

        vector<pair<int, int>> cand;
        droptop(i, 1, n + 1)
        {
            int makssub = n - sub[i];
            for (int ss : wec[i]) {
                if (ss != par[i])
                    makssub = max(makssub, sub[ss]);
            }
            cand.pb({makssub, i});
        }

        hotbox(cand);
        droptop(i, 0, k)
        {
            cout << cand[i].second << " ";
        }
        cout << "\n";
    }
}
