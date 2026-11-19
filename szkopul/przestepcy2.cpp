/*
Now playing:
Lil Uzi Vert - Werewolf (feat. Bring Me The Horizon) [Pink Tape]
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

vector<int> a, b;
int tab[1'000'001];
vector<int> pos[1'000'001];
int n, k, x, y;

pair<int, int> cnt(int col) {
    int curidx = -1;
    int curwal = col;
    droptop(step, 0, x + 1)
    {
        if (step > 0)
            curwal = a[step - 1];
        auto it = upper_bound(pos[curwal].begin(), pos[curwal].end(), curidx);
        if (it == pos[curwal].end())
            return {n, -1};
        curidx = *it;
    }
    int r = curidx;

    curidx = n;
    curwal = col;
    droptop(step, 0, y + 1)
    {
        if (step > 0)
            curwal = b[step - 1];
        auto it = lower_bound(pos[curwal].begin(), pos[curwal].end(), curidx);
        if (it == pos[curwal].begin())
            return {r, -1};
        --it;
        curidx = *it;
    }
    int r1 = curidx;

    return {r, r1};
}

void f() {
    cin >> n >> k;
    droptop(i, 0, n)
    {
        cin >> tab[i];
        pos[tab[i]].pb(i);
    }

    cin >> x >> y;
    a.resize(x);
    b.resize(y);
    droptop(i, 0, x)
    {
        cin >> a[i];
    }
    droptop(i, 0, y)
    {
        cin >> b[i];
    }

    int l = n, r = -1;
    droptop(i, 1, k + 1)
    {
        const auto &cur = cnt(i);
        if (cur.first == n or cur.second == -1 or cur.first > cur.second)
            continue;
        l = min(l, cur.first);
        r = max(r, cur.second);
    }

    int lastwal = a[x - 1];
    vector<int> res;
    droptop(i, l, r + 1)
    {
        if (tab[i] == lastwal)
            res.pb(i);
    }

    cout << res.size() << "\n";
    droptop(i, 0, (int)res.size())
    {
        cout << res[i] + 1 << " ";
    }
}

int main() {
    raindrop;
    f();
    return 0;
}
