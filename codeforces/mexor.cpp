/*
Now playing:
Lil Peep - OMFG [HELLBOY]
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

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 1) {
            if (k == 1) {
                cout << "YES\n0\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        int need = k ^ n;

        vector<int> tab(n);
        droptop(i, 0, n)
        {
            tab[i] = i;
        }

        vector<int> s;
        ll cur = 0;
        for (int bit = 20; bit >= 0; bit--) {
            if ((need >> bit) & 1) {
                droptop(i, 0, n)
                {
                    if ((tab[i] >> bit) & 1) {
                        s.pb(tab[i]);
                        cur ^= tab[i];
                        break;
                    }
                }
            }
        }

        if (cur != need) {
            cout << "NO\n";
            continue;
        }

        vector<int> res;
        vector<bool> wiz(n, 0);

        for (int x : s) {
            wiz[x] = true;
        }

        droptop(i, 1, n)
        {
            if (wiz[i])
                continue;
            res.pb(i);
        }
        res.pb(0);
        droptop(i, 0, n)
        {
            if (wiz[i]) {
                res.pb(i);
            }
        }
        cout << "YES\n";
        droptop(i, 0, n)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
