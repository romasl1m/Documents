/*
Now playing:
Young Thug - Chanel (Go Get It) [feat. Gunna and Lil Baby] [Slime Language]
*/
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> tab(n);
        map<ll, ll> oft, res;
        droptop(i, 0, n)
        {
            cin >> tab[i];
            oft[tab[i]]++;
        }
        if (not oft.count(0)) {
            cout << "-1\n";
            continue;
        }

        ll last = 0, cnt = 0, lastb = 0;
        bool ok = true;

        for (const auto &[curb, curcnt] : oft) {
            // cerr << "map chk: " << curb << " " << cnt << endl;
            if (curb != 0) {
                ll dif = curb - lastb;
                if (dif % cnt != 0) {
                    ok = false;
                    break;
                }

                ll newa = dif / cnt;
                if (newa <= last) {
                    ok = false;
                    break;
                }

                res[lastb] = newa, last = newa;
                // cerr << "deb: " << dif << " " << curb << " " << lastb << " " << newa << endl;
            }
            lastb = curb, cnt = curcnt;
        }
        res[lastb] = last + 1;

        if (not ok or not oft.count(0)) {
            cout << "-1\n";
            continue;
        }
        droptop(i, 0, n)
        {
            cout << res[tab[i]] << " ";
        }
        cout << "\n";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
