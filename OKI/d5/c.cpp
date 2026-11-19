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

struct s {
    int a, b;
    double len;
};
vector<s> roads;
vector<vector<double>> dp;

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        roads.resize(m);
        droptop(i, 0, m)
        {
            int a, b;
            double len;
            roads[i] = {a, b, len};
        }
        dp.resize(n + 1, vector<double>(n));

        droptop(i, 1, n + 1)
        {
            for (const auto &[a, b, len] : roads) {
                if (dp[i - 1][a] != 1e18) {
                    dp[i][b] = min(dp[i][b], dp[i - 1][a] - len);
                }
            }
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
