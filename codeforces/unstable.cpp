/*
Now playing:
Future - Fine China [Future and Juice WRLD Present... WRLD ON DRUGS]
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
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n, k;
        cin >> n >> k;
        vector<int> tab(n);
        vector<int> quan(n + 1);
        droptop(i, 0, n)
        {
            cin >> tab[i];
            quan[tab[i]]++;
        }
        vector<int> wec;
        droptop(i, 1, n + 1)
        {
            if (quan[i] == 0)
                continue;
            wec.pb(quan[i]);
        }
        hotbox(wec);
        vector<int> wec1 = wec;
        wec1.erase(unique(wec1.begin(), wec1.end()), wec1.end());
        int p = wec1.size(), m = wec.size();
        ll res = 0, curs = m, sum = n;
        int idx = 0;
        droptop(i, 0, p)
        {
            ll cur = k - sum;
            if (cur % curs == 0 and cur / curs >= 1 - wec1[i]) {
                res++;
            }
            while (idx < m and wec[idx] == wec1[i]) {
                curs--, sum -= wec[idx], idx++;
            }
        }
        cout << res << "\n";
    }
}
