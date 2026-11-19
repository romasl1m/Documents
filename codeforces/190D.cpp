/*
Now playing:
Juice WRLD - Tell Me U Luv Me (with Trippie Redd) [Legends Never Die]
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

void f() {
    int n, k;
    cin >> n >> k;
    vector<int> tab(n);

    droptop(i, 0, n)
    {
        cin >> tab[i];
    }

    int cur = 0;
    // unordered_map<ll, int> mapa;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
