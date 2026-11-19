/*
Now playing:
Playboi Carti - DIFFERENT DAY [MUSIC - SORRY 4 DA WAIT]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int long long
vector<ll> last;
vector<ll> nl;
ll lastsiz = 0;
ll d;
ll check(ll mid) {
    ll res = 0;
    // droptop(min(0LL, -mid), max((ll)last.size(), (ll)nl.size() - mid))
    for (ll i = min(0LL, -mid); i < max((ll)last.size(), (ll)nl.size() - mid); i++) {
        ll a, b;
        // if (i < 0) {
        //     a = 0;
        // } else if (i >= last.size()) {
        //     a = d;
        // } else {
        //     a = last[i];
        // }
        //
        // if (i + mid < 0) {
        //     b = 0;
        // } else if (i + mid >= nl.size()) {
        //     b = d;
        // } else {
        //     b = nl[i + mid];
        // }
        a = (i < 0 ? 0 : (i >= (ll)last.size() ? d : last[i]));
        b = (i + mid < 0 ? 0 : (i + mid >= nl.size() ? d : nl[i + mid]));
        res += llabs(a - b);
    }
    return res;
}
signed main() {
    raindrop;
    int n = 1;
    cin >> n >> d;
    int s;
    cin >> s;
    lastsiz = s;
    droptop(0, s)
    {
        int x;
        cin >> x;
        nl.pb(x);
    }
    for (int a = 1; a < n; a++) {
        cin >> s;
        last.clear(), swap(last, nl);
        droptop(0, s)
        {
            int x;
            cin >> x;
            nl.pb(x);
        }
        ll l = -lastsiz, r = s;
        lastsiz = s;
        ll res = 9223372036854775807;
        while (l + 3 < r) {
            ll a1 = check(l + (r - l) / 3), b = check(r - (r - l) / 3);
            res = min(res, min(a1, b));
            if (a1 <= b) {
                r = r - (r - l) / 3 - 1;
            } else {
                l = l + (r - l) / 3 + 1;
            }
        }
        droptop(l, r + 1)
        {
            res = min(res, check(i));
        }
        cout << res << "\n";
    }
    return 0;
}
