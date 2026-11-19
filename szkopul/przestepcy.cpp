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

int nxt[1'000'001];
int last[1'000'001];
int sq[1'000'001];
int tab[1'000'001];
int color[1'000'001][2];
int pos[1'000'001];
int ft[1'000'001][2], res[1'000'001][2];

int n, k, x1, y1;

void fd(int xy) {
    int cur = 0;
    droptop(i, 0, k)
    {
        pos[i] = n;
    }

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = pos[tab[i]], pos[tab[i]] = i;
    }

    droptop(i, 1, xy + 1)
    {
        while ((pos[color[i][xy]] < cur) and (pos[color[i][xy]] < n))
            pos[color[i][xy]] = nxt[pos[color[i][xy]]];

        cur = pos[color[i][xy]], sq[i] = cur;
    }

    droptop(i, 0, n)
    {
        sq[0] = i;
        int cur = 0;

        while ((cur <= xy) and (sq[cur] >= sq[cur + 1])) {
            while ((sq[cur] >= sq[cur + 1]) and (sq[cur + 1] < n))
                sq[cur + 1] = nxt[sq[cur + 1]];
            cur++;
        }

        ft[i][xy] = sq[xy];
    }

    if (xy == x1) {
        droptop(i, 0, n)
        {
            res[i][0] = n;
        }
        droptop(i, 0, n)
        {
            res[tab[i]][0] = min(res[tab[i]][0], ft[i][0]);
        }
    } else {
        droptop(i, 0, n)
        {
            res[tab[i]][1] = max(res[tab[i]][1], n - 1 - ft[i][1]);
        }
    }
}

void f() {
    cin >> n >> k;
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    cin >> x1 >> y1;
    droptop(i, 0, x1)
    {
        cin >> color[i][0];
        color[i][0]--;
    }
    droptop(i, 0, y1)
    {
        cin >> color[i][1];
        color[i][1]--;
    }

    fd(x1), reverse(tab, tab + n), fd(y1), reverse(tab, tab + n);

    int res1 = n, res2 = 0;
    droptop(i, 0, k)
    {
        if (res[i][0] <= res[i][1])
            res1 = min(res1, res[i][0]), res2 = max(res2, res[i][1]);
    }

    vector<int> wec;
    droptop(i, res1, res2 + 1)
    if (tab[i] == color[y1][1])
        wec.pb(i);

    cout << wec.size() << "\n";
    for (int x : wec) {
        cout << x << " ";
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
