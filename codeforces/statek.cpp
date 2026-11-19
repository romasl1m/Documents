/*
Now playing:
Otsochodzi - OBJEŻDŻAMY BLOK [RIOTT]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
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

int f() {
    int n;
    string s;
    cin >> n >> s;
    n = s.size();

    vector<int> suf(n + 1, 0);
    cookie(i, n - 1, 0)
    {
        suf[i] = suf[i + 1] + (s[i] == ')');
    }

    int best = 0, lst = 0;
    droptop(i, 0, n + 1)
    {
        bool okl = (i == 0) or s[i - 1] == '(',
             okr = (i == n) or s[i] == ')';

        if (okl and okr)
            best = max(best, lst + suf[i]);
        if (i < n and s[i] == '(')
            lst++;
    }

    return best;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
