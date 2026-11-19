/*
Now playing:
Huncho Jack - Modern Slavery [Huncho Jack, Jack Huncho]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, int>> wec(n);
        droptop(i, 0, n)
        {
            ll x;
            int h;
            cin >> x >> h;
            wec[i] = {x, h};
        }
        droptop(i, 0, n - 1)
        {
            if (wec[i].second >= wec[i + 1].first - wec[i].first or wec[i + 1].second >= wec[i + 1].first - wec[i].first)
                continue;
        }
    }
}
