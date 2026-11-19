/*
Now playing:
mgk - maybe (feat. Bring Me The Horizon) [mainstream sellout]
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

vector<int> wec[200'001];
vector<int> deps[200'001];
int dep[200'001];
int tab[200'001];
void clean(int n) {
    droptop(i, 1, n + 1)
    {
        wec[i].clear(), dep[i] = 0, deps[i].clear(), tab[i] = 0;
    }
}

void dfs(int w, int p) {
    dep[w] = dep[p] + 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;

        // cerr << dep[w] << " " << dep[w] << " om" << endl;
        dfs(ss, w);
    }
}

void f() {
    int n;
    cin >> n;
    clean(n);

    droptop(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].pb(b), wec[b].pb(a);
    }
    dfs(1, 0);

    droptop(i, 1, n + 1)
    {
        deps[dep[i]].pb(i);
    }

    int l = 2, r = (n << 1);
    int cur = 0;
    droptop(i, 1, n + 1)
    {
        // cerr << dep[i] << " ";
        if (cur) {
            for (int ss : deps[i]) {
                tab[ss] = r, r -= 2;
            }
        } else {
            for (int ss : deps[i]) {
                tab[ss] = l, l += 2;
            }
        }
        cur ^= 1;
    }

    bool ok = false;
    droptop(i, 1, n + 1)
    {
        for (int ss : wec[i]) {
            if (dep[ss] < dep[i])
                continue;
            if (abs(tab[ss] - tab[i]) == 2) {
                // cerr << "here " << i << " " << ss << " " << tab[i] << " " << tab[ss] << endl;
                tab[ss] = tab[i] - 1, ok = true;
                break;
            }
        }
        if (ok)
            break;
    }

    droptop(i, 1, n + 1)
    {
        cout << tab[i] << " ";
    }
    cout << "\n";
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
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
