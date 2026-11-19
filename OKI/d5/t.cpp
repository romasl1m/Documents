/*
Now playing:

*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[100'001];
vector<int> rew[100'001];
int tab[100'001];
vector<int> ord;
bool wiz[100'001];
vector<int> zout, zin;
bool ok[100'001];
vector<vector<int>> dag;
bool mat[100'001];
bool fail[100'001];
int wiz1[100'001];

int cur1 = 0;
int dfs3(int w) {
    if (wiz1[w] == cur1 || fail[w])
        return 0;
    wiz1[w] = cur1;
    if (ok[w] && !mat[w]) {
        mat[w] = true;
        return w;
    }
    for (int ss : dag[w]) {
        int res = dfs3(ss);
        if (res)
            return res;
    }
    fail[w] = true;
    return 0;
}

int cur = 0;
void dfs(int w) {
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    ord.pb(w);
}

void dfs2(int w) {
    wiz[w] = true;
    tab[w] = cur;
    for (int ss : rew[w]) {
        if (wiz[ss])
            continue;
        dfs2(ss);
    }
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
            rew[b].pb(a);
        }

        if (n == 1) {
            cout << 0 << "\n";
            return 0;
        }

        droptop(i, 1, n + 1)
        {
            if (wiz[i])
                continue;
            dfs(i);
        }

        droptop(i, 1, n + 1)
        {
            wiz[i] = false;
        }

        for (int i = ord.size() - 1; i >= 0; i--) {
            if (wiz[ord[i]])
                continue;
            cur++;
            dfs2(ord[i]);
        }

        if (cur == 1) {
            cout << 0 << "\n";
            return 0;
        }

        vector<int> rep(cur + 1);
        droptop(i, 1, n + 1)
        {
            rep[tab[i]] = i;
        }

        dag.resize(cur + 1);
        vector<int> in(cur + 1, 0), out(cur + 1, 0);

        droptop(i, 1, n + 1)
        {
            for (int ss : wec[i]) {
                if (tab[i] != tab[ss]) {
                    dag[tab[i]].pb(tab[ss]);
                    out[tab[i]]++;
                    in[tab[ss]]++;
                }
            }
        }

        droptop(i, 1, cur + 1)
        {
            hotbox(dag[i]);
            dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
        }

        droptop(i, 1, cur + 1)
        {
            if (in[i] == 0)
                zin.pb(i);
            if (out[i] == 0) {
                zout.pb(i);
                ok[i] = true;
            }
        }

        vector<pair<int, int>> mp;
        vector<int> bad;
        for (int ss : zin) {
            cur1++;
            int res = dfs3(ss);
            if (res) {
                mp.pb({ss, res});
            } else {
                bad.pb(ss);
            }
        }

        vector<int> badzout;
        for (int ss : zout) {
            if (!mat[ss]) {
                badzout.pb(ss);
            }
        }

        vector<pair<int, int>> roads;
        int siz = mp.size();
        droptop(i, 0, siz - 1)
        {
            roads.pb({mp[i].second, mp[i + 1].first});
        }
        roads.pb({mp[siz - 1].second, mp[0].first});

        int k = min(bad.size(), badzout.size());
        droptop(i, 0, k)
        {
            roads.pb({badzout[i], bad[i]});
        }
        droptop(i, k, bad.size())
        {
            roads.pb({mp[0].second, bad[i]});
        }
        droptop(i, k, badzout.size())
        {
            roads.pb({badzout[i], mp[0].first});
        }

        cout << roads.size() << "\n";
        for (const auto &[a, b] : roads) {
            cout << rep[a] << " " << rep[b] << "\n";
        }
    }
    return 0;
}
// 200 linijek
