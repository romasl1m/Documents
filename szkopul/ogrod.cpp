/*
Now playing:
Linkin Park - Forgotten [Hybrid Theory (Bonus Edition)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

// int colorf(const int &x, const int &y) {
//     if (x >= 1) {
//         return 2;
//     } else if (x <= -1) {
//         return 1;
//     } else if (y >= 1) {
//         return 3;
//     }
//     return 4;
// }
int colorf(const int &x, const int &y) {
    if (abs(x) >= abs(y)) {
        return x > 0 ? 1 : 2;
    }
    if (y > 0) {
        return (x & 1) + 1;
    }
    return ((x + y) & 1) + 1;
}

void ft1() {
    droptop(y, -1000, 1001)
    {
        droptop(x, -1000, 1001)
        {
            if (x < 0) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
        cout << "\n";
    }
    cout << "2\n";
    cout << "1 1 1 1 1 E\n";
    cout << "2 2 2 2 2 W\n";
}

int f() {
    int k, t;
    cin >> k >> t;
    if (t) {
        ft1();
        return 0;
    }

    droptop(y, -1000, 1001)
    {
        droptop(x, -1000, 1001)
        {
            cout << colorf(x, y) << " ";
        }
        cout << "\n";
    }

    set<string> wec;
    wec = {
        "1 1 1 1 1 W",
        "2 2 2 2 2 E",
        "2 1 1 1 1 S",
        "2 2 1 2 1 N",
        "1 2 2 1 2 N",
        "1 1 2 1 2 N",
        "2 2 1 2 2 N",
        "2 1 1 2 2 E",
        "1 2 2 2 2 S",
        "1 2 1 1 2 W",
        "2 2 2 1 2 N",
        "1 1 1 1 2 W",
        "2 1 1 2 1 N",
        "1 1 1 2 1 W"};
    // set<int> uniq;
    // set<string> wec = {"7 1 2 2 1 1 S", "1 2 2 1 2 S", "1 2 2 2 2 W", "2 2 2 1 1 S", "2 2 2 1 2 S", "2 2 2 2 1 W", "2 2 2 2 2 W"};

    char tab[5] = {'0', 'E', 'W', 'N', 'S'};
    // droptop(x, -400, 401)
    // {
    //     droptop(y, -400, 401)
    //     {
    //
    //         if ((abs(x) <= 1 and abs(y) <= 1) or (abs(x) <= 1 and abs(y) == 2) or (abs(x) == 2 and abs(y) <= 1))
    //             continue;
    //
    //         int color = colorf(x, y);
    //
    //         string s = to_string(color) + " " + to_string(colorf(x, y + 1)) + " " + to_string(colorf(x + 1, y)) + " " + to_string(colorf(x, y - 1)) + " " + to_string(colorf(x - 1, y)) + " " + tab[color];
    // wec.insert(s);

    // int cur = 0;
    // if (colorf(x - 1, y - 1) == 2)
    //     cur |= 1;
    // if (colorf(x - 1, y) == 2)
    //     cur |= 2;
    // if (colorf(x - 1, y + 1) == 2)
    //     cur |= 4;
    // if (colorf(x, y - 1) == 2)
    //     cur |= 8;
    // if (colorf(x, y) == 2)
    //     cur |= 16;
    // if (colorf(x, y + 1))
    //     cur |= 32;
    // if (colorf(x + 1, y - 1))
    //     cur |= 64;
    // if (colorf(x + 1, y))
    //     cur |= 128;
    // if (colorf(x + 1, y + 1))
    //     cur |= 256;
    // uniq.insert(cur);
    // }
    cout << wec.size() << "\n";
    for (const string &s : wec) {
        cout << s << "\n";
    }

    // cerr << "unique positions:\n";
    // for (const auto x : uniq) {
    //     cerr << (x & 4 ? 2 : 1) << " " << (x & 32 ? 2 : 1) << " " << (x & 256 ? 2 : 1) << endl;
    //     cerr << (x & 2 ? 2 : 1) << " " << (x & 16 ? 2 : 1) << " " << (x & 128 ? 2 : 1) << endl;
    //     cerr << (x & 1 ? 2 : 1) << " " << (x & 8 ? 2 : 1) << " " << (x & 64 ? 2 : 1) << endl;
    //     cerr << endl;
    // }
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
