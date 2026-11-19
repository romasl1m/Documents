/*
Now playing:
Internet Money - 556 (feat. BabyBartier and Sir Untre) [556 (feat. BabyBartier and Sir Untre)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[500'001];
vector<pair<int, int>> start[500'001];
vector<int> ord;
bool wiz[500'001];
int in[500'001];
int out[500'001];
int pref[500'001];
int suf[500'001];
// int maksstart[500'001];
// int maksend[500'001];
int pos[500'001];
int indeg[500'001];

void dfs(int w = 1) {
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    ord.pb(w);
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        droptop(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
        }
        droptop(i, 1, n + 1)
        {
            if (wiz[i])
                continue;
            dfs(i);
        }

        reverse(ord.begin(), ord.end());

        droptop(i, 0, n)
        {
            pos[ord[i]] = i;
        }

        for (int w : ord) {
            for (int ss : wec[w]) {
                in[ss] = max(in[ss], in[w] + 1);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int w = ord[i];
            for (int ss : wec[w]) {
                out[w] = max(out[ss] + 1, out[w]);
            }
        }

        pref[0] = in[ord[0]];
        droptop(i, 1, n)
        {
            pref[i] = max(pref[i - 1], in[ord[i]]);
        }
        suf[n - 1] = out[ord[n - 1]];
        droptop(i, 2, n + 1)
        {
            suf[n - i] = max(suf[n - i + 1], out[ord[n - i]]);
        }

        droptop(w, 1, n + 1)
        {
            for (int ss : wec[w]) {
                if (pos[w] + 1 <= pos[ss] - 1) {
                    int len = in[w] + out[ss] + 1;
                    start[pos[w] + 1].pb({len, pos[ss] - 1});
                }
            }
        }
        // droptop(w, 1, n + 1)
        // {
        //     for (int ss : wec[w]) {
        //         maksstart[ord[w]] = max(maksstart[ord[w]], in[w] + 1 + out[ss]);
        //         maksend[ord[ss]] = max(maksend[ord[ss]], in[w] + 1 + out[ord[w]]);
        //     }
        // }

        priority_queue<pair<int, int>> q;
        int res = ord[0], war = 1e9;
        droptop(i, 0, n)
        {
            for (auto [len, ss] : start[i]) {
                q.push({len, ss});
            }
            while (not q.empty() and q.top().second < i) {
                q.pop();
            }
            int l = (i > 0) ? pref[i - 1] : 0, r = (i < n - 1) ? suf[i + 1] : 0, jump = not q.empty() ? q.top().first : 0;
            int cur = max({l, r, jump});
            if (cur < war) {
                war = cur;
                res = ord[i];
            }
        }
        // droptop(i, 0, n)
        // {
        //     int w = ord[i];
        //     int cur = max({out[w], in[w]});
        //     if (war < cur) {
        //         war = cur, res = w;
        //     }
        // }
        cout << res << " " << war;
        return 0;
    }
}
