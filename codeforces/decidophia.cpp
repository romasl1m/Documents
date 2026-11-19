#include <iostream>
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
#define int ll
signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n, d;
        cin >> n >> d;
        vector<int> tab(n * 3 + 10);
        vector<ll> wec(n * 3 + 10);
        vector<ll> res(n * 3 + 10);
        droptop(1, n + 1)
        {
            cin >> tab[i];
            tab[i + n] = tab[i + (n << 1)] = tab[i];
        }
        droptop(1, n * 3 + 1)
        {
            wec[i] = wec[i - 1] + tab[i];
        }
        droptop(n + 1, (n << 1) + 1)
        {
            res[i - n] = (ll)((d << 1 | 1) * tab[i] - wec[i + d] + wec[i - d - 1]);
        }
        ll resc = 0;
        droptop(1, n + 1)
        {
            resc += max((ll)0, res[i]);
        }
        cout << resc << "\n";
    }
}
