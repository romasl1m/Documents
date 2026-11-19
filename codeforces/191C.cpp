/*
Now playing:
Linkin Park - No More Sorrow [Minutes to Midnight]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> wec[100'001];
int lca[100'001][19];
int dep[100'001];
int pref[100'001];

void dfs(int w, int p) {
    lca[w][0] = p;
    droptop(i, 1, 19)
    {
        lca[w][i] = lca[lca[w][i - 1]][i - 1];
    }

    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dep[ss] = dep[w] + 1;
        dfs(ss, w);
    }
}

int lift(int a, int dif) {
    for (int i = 18; i >= 0; i--) {
        if (dif & (1 << i))
            a = lca[a][i];
    }
    return a;
}

int lcaf(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    a = lift(a, dep[a] - dep[b]);
    if (a == b)
        return a;

    for (int i = 18; i >= 0; i--) {
        if (lca[a][i] != 0 and lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    }
    return lca[a][0];
}

map<pair<int, int>, int> res;
void sum(int w, int p) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        sum(ss, w);

        pref[w] += pref[ss];
        res[{min(w, ss), max(w, ss)}] = pref[ss];
    }
}

pair<int, int> roads[100'001];
void f() {
    int n;
    cin >> n;
    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
        roads[i] = {min(a, b), max(a, b)};
    }
    dfs(1, 0);

    int k;
    cin >> k;
    droptop(i, 0, k)
    {
        int a, b;
        cin >> a >> b;

        // cerr << "check " << a << " " << b << " " << lcaf(a, b) << endl
        //      << endl;
        pref[a]++, pref[b]++, pref[lcaf(a, b)] -= 2;
    }
    sum(1, 0);

    droptop(i, 1, n)
    {
        cout << res[roads[i]] << " ";
    }
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
