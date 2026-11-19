/*
Now playing:
Lil Peep - Hate Me [Come Over When You're Sober, Pt. 2]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
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

int n;
bool dp[100'000'001][2];
const string maks = "?????????";
void genf(const string &s, int cur, int idx, const bool &type) {
    if (idx == n) {
        dp[cur][type] = true;
        return;
    }
    if (s[idx] == '?') {
        droptop(i, 0, 10)
        {
            genf(s, cur * 10 + i, idx + 1, type);
        }
    } else
        genf(s, cur * 10 + s[idx] - '0', idx + 1, type);
}

int maksb(string &b) {
    droptop(i, 0, b.length())
    {
        if (b[i] == '?')
            b[i] = '9';
    }
    return stoi(b);
}

bool cleanf(string &s) {
    droptop(i, 0, s.length())
    {
        if (s[i] == '?')
            return false;
    }
    return true;
}

ll nwd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll res = 1;
void genonef(const string &s, ll cur, int idx, const ll &scd) {
    if (idx == n) {
        // res = max(res, nwd(cur, scd));
        if (cur)
            res = max(res, nwd(cur, scd));
        return;
    }
    if (s[idx] == '?') {
        droptop(i, 0, 10)
        {
            genonef(s, cur * 10 + i, idx + 1, scd);
        }
    } else
        genonef(s, cur * 10 + s[idx] - '0', idx + 1, scd);
}

int f() {
    string a, b;
    cin >> n >> a >> b;

    if (a == maks and b == maks) {
        return 999'999'999;
    }
    if (b == maks)
        swap(a, b);
    if (a == maks) {
        return maksb(b);
    }

    int c = 0, d = 0, pos = 1;
    if (cleanf(a) and stoll(a)) {
        genonef(b, 0LL, 0, stoll(a));
        return res;
    }
    if (cleanf(b) and stoll(b)) {
        genonef(a, 0LL, 0, stoll(b));
        return res;
    }

    droptop(i, 0, n)
    {
        pos *= 10;
    }
    genf(a, c, 0, false), genf(b, d, 0, true);
    cookie(i, pos - 1, 1)
    {
        bool ac = false, bc = false;
        for (int j = i; j < pos and not(ac and bc); j += i) {
            ac |= dp[j][0], bc |= dp[j][1];
        }
        if (ac and bc)
            return i;
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        cout << f() << "\n";
    }
    return 0;
}
