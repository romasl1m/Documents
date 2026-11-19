/*
Now playing:
Juice WRLD - Go Hard 2.0 [Fighting Demons (Deluxe)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<pair<int, int>> horizontal[10'005], vertical[10'005];
vector<int> sweep[10'005];

int tab[10'005];
void add(int pos, int war) {
    for (int i = pos; i < 10'005; i += i & -i)
        tab[i] += war;
}
int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += tab[i];
    return res;
}
void f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5001, x2 += 5001, y1 += 5001, y2 += 5001;

        if (x2 == x1)
            vertical[x1].pb({min(y1, y2), max(y1, y2)});
        else
            horizontal[y1].pb({min(x1, x2), max(x1, x2)});
    }

    ll res = 0;
    droptop(ybottom, 0, 10'005)
    {
        for (const auto [l, r] : horizontal[ybottom]) {
            memset(tab, 0, sizeof tab);

            droptop(xvert, l, r + 1)
            {
                for (const auto [bottom, up] : vertical[xvert]) {
                    if (bottom <= ybottom and ybottom < up)
                        sweep[up].pb(xvert), add(xvert, 1);
                }
            }

            droptop(yup, ybottom + 1, 10'005)
            {
                for (const auto [left, right] : horizontal[yup]) {
                    int opt = query(right) - query(left - 1);
                    res += (ll)((opt * (opt - 1)) >> 1);
                }
                for (int x : sweep[yup])
                    add(x, -1);
                sweep[yup].clear();
            }
        }
    }
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
