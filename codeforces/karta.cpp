/*
Now playing:
Linkin Park - Heavy Is the Crown [Heavy Is the Crown]
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
        int n, a, b;
        cin >> n >> a >> b;
        int ucz = 0, nau = 0, esc = 0;
        int minc = 0, maks = 0;
        bool ok = true;
        droptop(0, n)
        {
            int x;
            cin >> x;
            if (x == 0) {
                esc++;
            } else if (x == 1) {
                ucz++;
            } else {
                nau++;
            }
            int clow = max({0, ucz - esc, ucz + nau - esc - b});
            int cmaks = min({ucz, a, ucz + nau - esc});

            if (x == 1) {
                minc = max(clow, minc + 1);
                maks = min(maks + 1, cmaks);
            } else if (x == 2) {
                minc = max(clow, minc);
                maks = min(cmaks, maks);
            } else {
                minc = max(clow, minc - 1);
                maks = min(cmaks, maks);
            }

            if (minc > maks) {
                ok = false;
            }
        }
        if (not ok) {
            cout << -1 << "\n";
            continue;
        }
        cout << minc << " " << maks << "\n";
    }
}
