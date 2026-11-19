/*
Now playing:
Lil Peep - absolute in doubt [crybaby]
*/
#include <iostream>
#include <iomanip>
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
double p[100'001], c[100'001];

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(1, n + 1)
        {
            cin >> c[i] >> p[i];
            p[i] /= 100.0;
        }
        long double res = 0.0;
        for (int i = n; i >= 1; i--) {
            res = max(res, res * (1.0 - p[i]) + c[i]);
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
}
