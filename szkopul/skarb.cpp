/*
Now playing:
Lil Peep - worlds away [HELLBOY]
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

int fst[1'000'001];
int to[1'000'001];
int nxt[1'000'001];

bool wiz[1'000'001];
vector<int> ord;

int cur = 1;

void road(int w, int ss) {
    to[cur] = ss;
    nxt[cur] = fst[w];
    fst[w] = cur++;
}

void dfs(int w) {
    wiz[w] = true;
    // for (int ss : wec[w]) {
    for (int i = fst[w]; i != 0; i = nxt[i]) {
        int ss = to[i];
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    ord.pb(w);
}

void dfsrew(int w) {
    wiz[w] = true;
    // for (int ss : wec[w]) {
    for (int i = fst[w]; i != 0; i = nxt[i]) {
        int ss = to[i];
        if (wiz[ss])
            continue;
        dfsrew(ss);
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n + 1)
        {
            int x;
            cin >> x;
            road(x, i);
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
        int res = 0;
        for (int i = ord.size() - 1; i >= 0; i--) {
            if (wiz[ord[i]])
                continue;
            res++;
            dfsrew(ord[i]);
        }
        cout << res;
    }
}
