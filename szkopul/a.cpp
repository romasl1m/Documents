#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int colorf(const int &x, const int &y) {
    if (abs(x) >= abs(y)) {
        return x > 0 ? 1 : 2; // jednolite: 1 -> W, 2 -> E
    }
    if (y > 0) {
        return (x & 1) + 1; // paski pionowe -> S
    }
    return ((x + y) & 1) + 1; // szachownica -> N
}

// maska kierunkow zmniejszajacych |x|+|y| (bity wg tab: 1=E, 2=W, 3=S, 4=N)
int allowedf(const int &x, const int &y) {
    int m = 0;
    if (x < 0)
        m |= 1 << 1;
    if (x > 0)
        m |= 1 << 2;
    if (y > 0)
        m |= 1 << 3;
    if (y < 0)
        m |= 1 << 4;
    return m;
}

int f() {
    int k, t;
    cin >> k >> t;

    droptop(y, -1000, 1001)
    {
        droptop(x, -1000, 1001)
        {
            cout << colorf(x, y) << " ";
        }
        cout << "\n";
    }

    // map<string, int> wec;
    set<string> wec;
    char tab[5] = {'0', 'E', 'W', 'S', 'N'};
    droptop(y, -400, 401)
    {
        droptop(x, -400, 401)
        {
            if ((abs(x) <= 1 and abs(y) <= 1) or (abs(x) <= 1 and abs(y) == 2) or (abs(x) == 2 and abs(y) <= 1))
                continue;
            string s = to_string(colorf(x, y)) + " " + to_string(colorf(x, y + 1)) + " " + to_string(colorf(x + 1, y)) + " " + to_string(colorf(x, y - 1)) + " " + to_string(colorf(x - 1, y));
            if (x > 0)
                s += " W";
            else
                s += " E";
            wec.insert(s);
        }
    }
    cout << wec.size();
    for (const auto &p : wec) {
        cout << "\n"
             << p;
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
