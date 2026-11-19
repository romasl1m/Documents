/*
Now playing:
Travis Scott - WHO? WHAT! [ASTROWORLD]
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
vector<ll> wec = {0, 1};
int one[60'001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {

        droptop(2, 50'002)
        {
            wec.pb(wec.back() + (i << 1) + ((i - 2) << 1));
        }
        droptop(0, 50'000)
        {
            wec[i + 1] += wec[i];
        }

        one[1] = 1;
        droptop(2, 60'000)
        {
            one[i] = one[i - 1] + 2;
        }
        // for (int i = 0; i < 10; i++)
        //     cout << wec[i] << " " << one[i] << "\n";
        // cout << wec.back();
        ll a, b;
        cin >> a >> b;
        ll sum = (a << 1) + b;
        int l = 0, r = 50'000;
        while (l < r - 1) {
            // cout << l << " " << r << endl;
            int mid = (l + r) >> 1;
            if (wec[mid] > sum or 1LL * mid * mid > b) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << l;
    }
}
