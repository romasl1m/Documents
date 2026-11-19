/*
Now playing:
Linkin Park - More the Victim [Meteora 20th Anniversary Edition]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
int n, m;
vector<int> wec[500'001];
vector<int> rew[500'001];
vector<int> scc[500'001];

bool wiz[500'001];
vector<int> ord;
int cur = 0;
int war[500'001];
void dfs(int w) {
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    ord.pb(w);
}

void rewf(int w, const int cur) {
    wiz[w] = true;
    war[w] = cur;
    for (int ss : rew[w]) {
        if (wiz[ss])
            continue;
        rewf(ss, cur);
    }
}

void sccf() {
    droptop(1, n + 1)
    {
        if (wiz[i])
            continue;
        dfs(i);
    }
    droptop(1, n + 1)
    {
        wiz[i] = false;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (wiz[ord[i]])
            continue;
        rewf(ord[i], ++cur);
    }
}

vector<int> scc2[500'001];
bool good[500'001];

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        cin >> n >> m;
        droptop(0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            rew[b].pb(a);
        }

        sccf();

        droptop(1, n + 1)
        {
            for (int ss : wec[i]) {
                if (war[i] == war[ss])
                    continue;
                scc[war[i]].pb(war[ss]);
            }
        }

        droptop(1, cur + 1)
        {
            hotbox(scc[i]);
            scc[i].erase(unique(scc[i].begin(), scc[i].end()), scc[i].end());
            for (int ss : scc[i]) {
                scc2[ss].pb(i);
            }
        }

        droptop(1, cur + 1)
        {
            good[i] = true;
        }

        int r = -1;
        droptop(1, cur + 1)
        {
            if (i < r)
                good[i] = false;
            int mint = scc[i].empty() ? cur + 1 : scc[i][0];
            r = max(r, mint);
        }

        r = -1;
        for (int i = cur; i >= 1; i--) {
            int ri = cur - i + 1;
            if (ri < r)
                good[i] = false;
            int minr = scc2[i].empty() ? cur + 2 : (cur - scc2[i].back() + 1);
            r = max(r, minr);
        }

        vector<int> res;
        droptop(1, n + 1)
        {
            int skl = war[i];
            if (good[skl])
                res.pb(i);
        }

        cout << res.size() << "\n";
        droptop(0, res.size())
        {
            cout << res[i] << " ";
        }
        cout << "\n";

        return 0;
    }
}
