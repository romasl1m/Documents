/*
Now playing:

*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end());
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> wec(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            wec[i] = s;
        }
        hotbox(wec);

        return 0;
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
