/*
Now playing:
J. Cole - Poor Thang [The Fall-Off]
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

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        vector<ll> tab(n);
        droptop(0, n)
        {
            cin >> tab[i];
        }

        droptop(0, n)
        {

            ll res = 0;
            cout << res << " ";
        }
        cout << "\n";
    }
}
