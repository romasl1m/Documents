/*
Now playing:

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
int base[500'005];
constexpr int mod = 1e9 + 7;
void f(int n) {
    base[0] = 1;
    droptop(1, n + 1)
    {
        base[i] = (base[i - 1] * 26) % mod;
    }
}
signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    f(500'002);
    cookie(t)
    {
        string s;
        cin >> s;
        int n = s.length();
        int res = 0;
        int l = 0, r = n - 1;
        int lh = 0, rh = 0;
        int len = 0;
        while (l <= r) {
            lh = (lh * 26 + (s[l] - 'a')) % mod;
            rh = (rh + (s[r] - 'a') * base[len++]) % mod;

            if (lh == rh) {
                res += (l == r ? 1 : 2);
                lh = rh = 0;
                len = 0;
                // cout << "END " << l << " " << r << endl;
            }

            l++;
            r--;
        }
        if (lh > 0 or rh > 0)
            res++;
        cout << res << "\n";
    }
}
