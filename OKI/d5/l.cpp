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

int tab[500'001];
int res[500'001];
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 0, n)
        {
            cin >> tab[i];
        }
        res[0] = -1;
        vector<int> wec = {0};
        droptop(i, 1, n)
        {
            while (not wec.empty() and tab[i] >= tab[wec.back()])
                wec.pop_back();
            if (wec.empty())
                res[i] = -1;
            else
                res[i] = wec.back();
            wec.pb(i);
        }

        droptop(i, 0, n)
        {
            if (res[i] == -1) {
                cout << "PACIFIK\n";
            } else {
                cout << res[i] + 1 << "\n";
            }
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
