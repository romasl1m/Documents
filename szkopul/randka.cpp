/*
Now playing:
Fatt Smaxk - Smaxk Or Die (feat. Playboi Carti) [Smaxk Or Die (feat. Playboi Carti)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    int maks1 = max(a.first, a.second), maks2 = max(b.first, b.second);
    if (maks1 != maks2)
        return maks1 < maks2;
    int sum1 = a.first + a.second, sum2 = b.first + b.second;
    if (sum1 != sum2)
        return sum1 < sum2;
    return a.second < b.second;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
int wiz[500'001];
int lca[500'001][19];
int dep[500'001];
int cycle[500'001];
int siz[500'001];
int root[500'001];
int nxt[500'001];
int component[500'001];
bool in[500'001];
// void dfs(int w, int p = -1) {
//     wiz[w] = true;
//     lca[w][0] = p;
//     droptop(1, 19)
//     {
//         lca[w][i] = lca[lca[w][i - 1]][i];
//     }
//
// }
int lift(int x, int dif) {
    droptop(0, 19)
    {
        if (dif & (1 << i)) {
            x = lca[x][i];
        }
    }
    return x;
}
int lcaf(int a, int b) {
    int resa = 0, resb = 0;

    if (dep[a] < dep[b])
        swap(a, b);
    a = lift(a, dep[a] - dep[b]);
    // if (dep[b] > dep[a]) {
    //     lift(b, dep[b] - dep[a]);
    // } else {
    //     lift(a, dep[a] - dep[b]);
    // }
    if (a == b)
        return a;
    for (int i = 18; i >= 0; i--) {
        if (lca[a][i] != lca[b][i] and lca[a][i] != 0) {
            a = lca[a][i], b = lca[b][i];
        }
    }
    int cur = lca[a][0];
    return lca[a][0];
}
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n, k;
        cin >> n >> k;
        droptop(1, n + 1)
        {
            int x;
            cin >> x;
            nxt[i] = x;
        }
        int num = 0;
        droptop(1, n + 1)
        {
            if (not wiz[i]) {
                int cur = i;
                vector<int> path;
                while (not wiz[cur]) {
                    wiz[cur] = 1;
                    path.pb(cur);
                    cur = nxt[cur];
                }
                if (wiz[cur] == 1) {
                    num++;
                    int start = 0;
                    while (path[start] != cur)
                        start++;
                    int cursiz = path.size() - start;
                    int idx = 0;
                    droptop(start, path.size())
                    {
                        int w = path[i];
                        in[w] = true;
                        cycle[w] = idx++;
                        siz[num] = cursiz;
                        component[w] = num;
                        dep[w] = 0;
                        root[w] = w;
                    }
                }
                for (int w : path)
                    wiz[w] = 2;
            }
        }
        droptop(1, n + 1)
        {

            // cout << "I " << i << endl;
            if (in[i] or root[i] > 0)
                continue;
            vector<int> path;
            int cur = i;
            while (not in[cur] and root[cur] == 0) {
                path.pb(cur);
                // if (nxt[cur] == cur)
                //     break;
                cur = nxt[cur];
            }
            int r = root[cur];
            int id = component[cur];
            int curdep = dep[cur];
            for (int j = path.size() - 1; j >= 0; j--) {
                dep[path[j]] = ++curdep;
                root[path[j]] = r;
                component[path[j]] = id;
            }
        }
        droptop(1, n + 1)
        {
            lca[i][0] = nxt[i];
        }
        for (int j = 1; j < 19; j++) {
            droptop(1, n + 1)
            {
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
        cookie(k)
        {
            int a, b;
            cin >> a >> b;
            if (component[a] != component[b]) {
                cout << "-1 -1\n";
                continue;
            }
            if (root[a] == root[b]) {
                auto cur = lcaf(a, b);
                cout << dep[a] - dep[cur] << " " << dep[b] - dep[cur] << "\n";
            } else {
                int ra = root[a], rb = root[b];
                int cursiz = siz[component[ra]];
                // int ab = (siz[rb] - siz[a] + cursiz) % cursiz;
                // int ba = (siz[ra] - siz[b] + cursiz) % cursiz;
                int ab = (cycle[rb] - cycle[ra] + cursiz) % cursiz;
                int ba = (cycle[ra] - cycle[rb] + cursiz) % cursiz;
                pair<int, int> one = {dep[a] + ab, dep[b]}, two = {dep[a], dep[b] + ba};
                pair<int, int> res = (comp(one, two) ? one : two);
                cout << res.first << " " << res.second << "\n";
            }
        }
    }
}
