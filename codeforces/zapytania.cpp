/*
Now playing:
21 Savage - Rap Saved Me (feat. Quavo) [Without Warning]
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
const int base = 1e5 + 1;
int tab[base << 1];
void upd(char c, int pos) {
    pos += base;
    tab[pos] = (1 << (c - 'a'));
    pos >>= 1;
    while (pos > 0) {
        tab[pos] = tab[pos << 1] | tab[pos << 1 | 1];
        pos >>= 1;
    }
}
int zap(int l, int r) {
    l += base, r += base;
    int res = 0;
    while (l <= r) {
        if (l & 1)
            res |= tab[l++];
        if (not(r & 1))
            res |= tab[r--];
        l >>= 1, r >>= 1;
    }
    return res;
}
int main() {
    raindrop;
    string s;
    cin >> s;
    droptop(0, s.length())
    {
        upd(s[i], i);
    }
    int t = 1;
    cin >> t;
    cookie(t)
    {
        short cur;
        cin >> cur;
        if (cur == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            upd(c, pos - 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << __builtin_popcount(zap(l, r)) << "\n";
        }
    }
}
