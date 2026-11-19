/*
Now playing:
Lil Peep - Save That Shit [Come Over When You're Sober, Pt. 1]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
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
        int n;
        cin >> n;
        vector<int> tab(n + 1);
        vector<int> two(n + 1);
        bool l = false, r = false;
        droptop(1, n + 1)
        {
            int x;
            cin >> x;
            tab[i] = tab[i - 1] + (x == 2 or x == 3);
            two[i] = two[i - 1] + (x == 3);
        }

        vector<int> f(n + 1);
        droptop(0, n + 1)
        {
            f[i] = (two[i] << 1) - i;
        }
        vector<int> suf(n + 2, 1e9);
        for (int i = n - 1; i >= 1; i--) {
            suf[i] = min(f[i], suf[i + 1]);
        }
        bool ok = false;
        droptop(1, n - 1)
        {
            if ((tab[i] << 1) <= i and suf[i + 1] <= f[i]) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
