/*
Now playing:
Juice WRLD, Young Thug - Think Twice [Think Twice]
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

const int base1 = 29, base2 = 31,
          mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int hash1[2'001][2];
int hash2[2'001][2];

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        hash1[0][0] = (a[0] - 'a' * base1), hash1[0][1] = (a[0] - 'a' * base2);
        hash2[0][1] = (b[0] - 'a' * base1), hash1[0][1] = (b[0] - 'a' * base2);
        droptop(i, 1, n)
        {
            hash1[i][0] = (hash1[i - 1][0] + (a[0] - 'a' * base1)) % mod1,
            hash1[i][1] = (hash1[i - 1][1] + (a[0] - 'a' * base2)) % mod2;
        }
        droptop(i, 1, m)
        {
            hash2[i][0] = (hash2[i - 1][0] + (b[0] - 'a' * base1)) % mod1,
            hash2[i][1] = (hash2[i - 1][1] + (b[0] - 'a' * base2)) % mod2;
        }

        bool ok = false;
        droptop(i, 0, n)
        {
            if (a[i] == b[0]) {
                // if (check(i, n)) {
                //     ok = true;
                //     break;
                // }
            }
        }
        cout << (ok ? "yes\n" : "no\n");
    }
    bool ops = false; // -- no ops left behind
}
