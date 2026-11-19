/*
Now playing:

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "ftblib.h"
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

bool wiz[200'001];
vector<int> wec[200'001];
vector<int> pato;

void dfs(const int &w) {
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        dfs(ss);
    }
    pato.pb(w);
}
void patof(const int &n) {
    droptop(i, 1, n + 1)
    {
        if (wiz[i])
            continue;
        dfs(i);
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n = liczba_modyfikacji();
        droptop(i, 1, n + 1)
        {
            wec[i] = zaleznosci(i);
        }
        patof(n);

        int l = 0, r = n - 1, resres = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int cur[mid + 1];
            droptop(i, 0, mid + 1)
            {
                cur[i] = pato[i];
            }
            int res = uruchom(mid + 1, cur);
            if (res == 1) {
                resres = pato[mid], r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // cerr << l << " " << r << endl;
        odpowiedz(resres);
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
