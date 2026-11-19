/*
Now playing:
Linkin Park - Wastelands [The Hunting Party]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
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
int pref[1'000'001];
bool ok[1'000'001];
int okl[1'000'001];
int p[1'000'001];
int d[1'000'001];

void f(int n) {
    int sum = 0;
    droptop(i, 1, n + 1)
    {
        sum += tab[i];
        pref[i] = pref[i - 1] + tab[i];
    }
    if (sum < 0)
        return;

    int k0 = 1;
    droptop(i, 2, n + 1)
    {
        if (pref[k0] > pref[i])
            k0 = i;
    }
    k0 = (k0 == n ? 1 : k0 + 1);
    int cur = k0;
    do {
        ok[cur] = true;

        int nxt = (cur == 1 ? n : cur - 1);
        ll curs = tab[nxt];
        while (nxt != k0 and curs < 0) {
            // nxt = (nxt == 1 ? n : nxt - 1);
            curs += tab[nxt = (nxt == 1 ? n : nxt - 1)];
        }
        cur = nxt;
    } while (cur != k0);
}
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n + 1)
        {
            cin >> p[i] >> d[i];
            tab[i] = p[i] - d[i];
        }

        f(n);
        droptop(i, 1, n + 1)
        {
            okl[i] = ok[i];
            ok[i] = false;
        }

        droptop(i, 1, n + 1)
        {
            int dist = (i == 1 ? d[n] : d[i - 1]);
            int idx = n - i + 1;
            tab[idx] = p[i] - dist;
        }

        f(n);

        droptop(i, 1, n + 1)
        {
            cout << (ok[n - i + 1] or okl[i] ? "TAK\n" : "NIE\n");
        }
    }
}
