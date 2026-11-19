/*
Now playing:
Artemas - Sink or Swim [Sink or Swim]
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

vector<int> wec[1'000'001];
int dep[1'000'001];
int side[1'000'001];

vector<pair<int, int>> path, road; // path zbior A, road zbior b;
int cur = 3;

void adda1(int ida, int yb) {
    path[ida] = {road[yb].first, road[yb].second};
}
void addb1(int idb, int xa) {
    int w = path[xa].second,
        ss = cur++;

    wec[w].pb(ss), road[idb] = {w, ss}, path[xa].second = ss;
}

void adda2(int ida, int target) {
    path[ida] = path[target];
}
void addb2(int idb, int target) {
    int w = road[target].first,
        ss2 = road[target].second,
        ss = ++cur;

    wec[w].pb(ss), wec[ss].pb(ss2);

    road[idb] = {w, ss},
    road[target].first = ss;
}

void dfs(int w) {
    for (int ss : wec[w]) {
        dep[ss] = dep[w] + 1;
        dfs(ss);
    }
}

void f() {
    int q;
    cin >> q;
    if (q <= 5'000) {
        wec[1].pb(2), wec[2].pb(1);
        while (q--) {
            char c;
            int x;
            cin >> c >> x;
            if (c == '?') {
                cout << wec[x].size() << "\n";
            } else if (c == 'W') {
                wec[x].pb(cur), wec[cur++].pb(x);
            } else {
                for (int ss : wec[x]) {
                    wec[ss].pb(cur), wec[cur].pb(ss);
                }
                cur++;
            }
        }
    } else {
        wec[1].pb(2);
        road[1] = {1, 2}, path[1] = {1, 2};
        char c;
        int x;
        cin >> c >> x;
        if (c == '?') {
            cout << dep[path[x].second] - dep[path[x].first] << "\n";
        } else if (c == 'W') {
            int nxt = cur++;
            int target_side = side[x];
            side[new_id] = 1 - target_side; // Osoba wybredna ląduje w przeciwnym zbiorze

            if (target_side == 1) { // x jest w B, nowa osoba ląduje w A
                treeA.adda1(new_id, x);
                treeB.addb1(new_id, x);
            } else { // x jest w A, nowa osoba ląduje w B
                treeA.addb1(new_id, x);
                treeB.adda1(new_id, x);
            }
        } else {
        }
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
