/*
Now playing:
Bring Me The Horizon - AmEN! (feat. Lil Uzi Vert and Daryl Palumbo of Glassjaw) [POST HUMAN: NeX GEn]
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

int tab[100'001];
vector<pair<int, int>> wec[100'001];
int siz[100'001];
int dist[100'001];
// int in[100'001];
// int out[100'001];
// int cur = 0;

void dfs(int w, int p) {
    siz[w] = 1; // in[w] = cur++;

    for (const auto [ss, cost] : wec[w]) {
        if (ss == p)
            continue;
        dist[ss] = max({0, dist[w] + cost, cost});
        dfs(ss, w);
        siz[w] += siz[ss];
    }
}

int res = 0;
void check(int w, int p) {
    if (tab[w] < dist[w])
        res += siz[w]; //, cerr << "bad " << w << endl;
    else {
        for (const auto [ss, cost] : wec[w]) {
            if (ss == p)
                continue;
            check(ss, w);
        }
    }
}

void f() {
    int n;
    cin >> n;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }

    droptop(i, 2, n + 1)
    {
        int p, c;
        cin >> p >> c;

        wec[p].pb({i, c}), wec[i].pb({p, c});
    }

    dfs(1, 0);
    check(1, 0);
    cout << res;
}

signed main() {
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
