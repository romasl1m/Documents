/*
Now playing:

*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <sys/types.h>
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

int tab[300'001];
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i = n - 1; i >= 0; i--) {
            cin >> tab[i];
        }
        int res = 0, cur = 1;
        droptop(i, 0, n - 1)
        {
            if (tab[i + 1] > tab[i])
                cur++;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }
        cout << max(cur, res);
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
