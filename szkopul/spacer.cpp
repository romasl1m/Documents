/*
Now playing:
Juice WRLD - Living In The Moment [Living In This Moment]
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
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
vector<int> wec[300'001];
bool wiz[300'001];

int dfs(int w, int k) {
    int cur = 0, chl = 0;
    wiz[w] = true;
    for (int ss : wec[w]) {
        if (wiz[ss])
            continue;
        chl++;
        cur += dfs(ss, k);
    }
    return max(0, chl + cur - k);
}

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            droptop(i, 1, n + 1)
            {
                wiz[i] = false;
            }
            if (dfs(1, mid) == 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }
}
