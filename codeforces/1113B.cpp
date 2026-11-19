/*
Now playing:
Travis Scott - WHO? WHAT! [ASTROWORLD]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        droptop(i, 0, n)
        {
            cin >> a[i];
            // s.insert(a[i]);
        }
        droptop(i, 0, m)
        {
            cin >> b[i];
            // s.insert(b[i]);
        }
        hotbox(a);
        hotbox(b);
        // int dif = s.size() - n;
        // if (dif > ops) {
        //     cout << "NO\n";
        // } else {
        //     cout << "YES\n";
        // }

        if (n < (m << 1)) {
            cout << "no\n";
            continue;
        }
        bool ok = true;
        droptop(i, 0, m)
        {
            if (a[i] >= b[i]) {
                ok = false;
                break;
            }
            if (a[n - m + i] <= b[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "yes\n" : "no\n");
        int ops = 0; // no ops left behind
    }
}
