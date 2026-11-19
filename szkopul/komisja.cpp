/*
Now playing:
Lil Peep - interlude [HELLBOY]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[16'001];
vector<int> rew[16'001];
bool wiz[16'001];
int scc[16'001];
vector<int> ord;

int neg(int x) {
    return x + (x % 2 == 1 ? 1 : -1);
}
void dfs(int w) {
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    ord.pb(w);
}
void dfs2(int w, const int &cur) {
    scc[w] = cur;
    for (int ss : rew[w]) {
        if (not scc[ss]) {
            dfs2(ss, cur);
        }
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
            int nega = neg(a), negb = neg(b);
            wec[a].pb(negb), wec[b].pb(nega);
            rew[nega].pb(b), rew[negb].pb(a);
        }
        droptop(i, 1, (n << 1) | 1)
        {
            if (wiz[i])
                continue;
            dfs(i);
        }
        reverse(ord.begin(), ord.end());
        int cur = 0;
        droptop(i, 0, ord.size())
        {
            if (not scc[ord[i]]) {
                dfs2(ord[i], ++cur);
            }
        }
        droptop(i, 1, n + 1)
        {
            if (scc[(i << 1)] == scc[((i << 1) - 1)]) {
                cout << "NIE\n";
                return 0;
            }
        }
        droptop(i, 1, n + 1)
        {
            int a = (i << 1), b = a - 1;
            cout << (scc[a] > scc[b] ? a : b) << (i == n ? "" : "\n");
        }
    }
}
