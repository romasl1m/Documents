/*
Now playing:
MORGENSHTERN - TEASER [LAST ONE]
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

int tab[1'000'001];
int nxt[1'000'001];
int last[1'000'001];

int zap() {
    return 0;
}

int close(int j) {
    return 0;
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;

        droptop(i, 0, n)
        {
            cin >> tab[i];
            nxt[last[tab[i]]] = last[tab[i]] = i;
        }
        ll res = 0;
        int minl = 2'000'001;
        droptop(i, 1, n)
        {
            int all = n - zap();
            res += all;
            if (all > 0) {
                int j = min(n - 1, i + (n >> 1) - 1),
                    best = close(j);

                int len1 = best - i + 1,
                    len2 = n - len1;
                minl = min(minl, abs(len1 - len2));
            }
            int c = r[i];
            update(c, -1);
            if (nxt[i] <)
        }
    }
    bool ops = false; // -- no ops left behind
}
