/*
Now playing:
Linkin Park - Nobody Can Save Me [One More Light]
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
#define int long long
int tab[3];
signed main() {
    // raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        int x, y;
        cout << "? 1 2\n"
             << flush;
        cin >> x;
        cout << "? 2 1\n"
             << flush;
        cin >> y;
        int a = x - (y / 2);
        int b = (a - x);
        // cout << x << " " << y << " " << a << " " << b << endl;
        vector<int> res = {a, b};
        a = y;
        droptop(3, n + 1)
        {
            cout << "? 1" << " " << i << "\n"
                 << flush;
            int x;
            cin >> x;
            int cur = a - x;
            res.pb(cur);
            a += cur;
            // cerr << "ACUR " << x << " " << a << " " << cur << endl;
        }
        cout << "! ";
        droptop(0, n)
        {
            cout << res[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
        return 0;
    }
}
