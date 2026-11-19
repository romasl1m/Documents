/*
Now playing:
Linkin Park - Burning in the Skies [A Thousand Suns]
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
#define cll constexpr long long
#define cint constexpr int
vector<vector<int>> wec;
int dp[22][80];
void f() {
    for (auto &x : wec) {
        int O = x[0];
        int N = x[1];
        int w = x[2];
        for (int i = 21; i >= 0; i--) {
            for (int j = 79; j >= 0; j--) {
                int a = min(21, i + O);
                int b = min(79, j + N);
                dp[a][b] = min(dp[a][b], dp[i][j] + w);
            }
        }
    }
}
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int a, b;
        cin >> a >> b;
        int n;
        cin >> n;
        wec.resize(n, vector<int>(3));
        droptop(0, n)
        {
            int O, N, w;
            cin >> O >> N >> w;
            wec[i] = {O, N, w};
        }
        droptop(0, 22)
        {
            for (int j = 0; j <= 79; j++) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = 0;
        f();
        int res = 1e9;
        droptop(a, 22)
        {
            for (int j = b; j < 80; j++) {
                res = min(res, dp[i][j]);
            }
        }
        cout << res;
        // return 0;
    }
    // cout << "___DEBUG___\n";
    // for (int i = 0; i < 22; i++) {
    //     for (int j = 0; j < 80; j++) {
    //         if (dp[i][j] == 1e9)
    //             continue;
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
