/*
Now playing:

*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
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
#define int ll

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> tab(n);
        droptop(i, 0, n)
        {
            cin >> tab[i];
        }
        hotbox(tab);
        droptop(i, 0, n)
        {
            if (tab[i] < k)
                k += tab[i];
            else
                break;
        }
        cout << k;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
