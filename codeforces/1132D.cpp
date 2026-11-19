/*
Now playing:
Offset - Swing My Way [KIARI:OFFSET]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

bool sito[200'001];
int nxt[200'001];

int f() {
    int n;
    cin >> n;
    vector<int> tab(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
        cout << nxt[tab[i]] << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;

    int maks = 100'101;
    sito[0] = sito[1] = true;
    for (int i = 2; (ll)(i * i) <= maks; i++) {
        if (not sito[i]) {
            for (int j = i * i; j <= maks; j += i) {
                sito[j] = true;
            }
        }
    }

    int lst = -1;
    cookie(i, maks, 0)
    {
        if (not sito[i])
            lst = i;
        nxt[i] = lst;
    }

    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
