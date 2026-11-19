/*
Now playing:
Linkin Park - Heavy Is the Crown [Heavy Is the Crown]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int par[200'001];
int tab[200'001];
int n;
bool dp[200'001];
unordered_map<int, int> last;

bool checkf(int mid) {
    dp[0] = true;
    droptop(i, 1, n + 1)
    {
        dp[i] = false;
    }
    last.clear();

    droptop(i, 1, n + 1)
    {
        int pos = i - mid;
        if (pos >= 0 and dp[pos])
            last[tab[pos]] = pos;

        if (last.count(tab[i]))
            dp[i] = true, par[i] = last[tab[i]];

        if (not dp[i]) {
            droptop(j, 0, 26)
            {
                int cur = tab[i] ^ (1 << j);
                if (last.count(cur)) {
                    dp[i] = true, par[i] = last[cur];
                    break;
                }
            }
        }
    }
    // droptop(i, 1, n + 1)
    // {
    //     cerr << (dp[i] ? 1 : 0);
    // }
    // cerr << endl;
    return dp[n];
}

void f() {
    cin >> n;
    droptop(i, 1, n + 1)
    {
        char c;
        cin >> c;
        tab[i] = tab[i - 1] ^ (1 << (c - 'a'));
    }
    int l = 1, r = n, res;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        // cerr << mid << " " << l << " " << r << endl;
        if (checkf(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    vector<pair<int, int>> wec;
    int cur = n;
    while (cur) {
        wec.pb({par[cur], cur}), cur = par[cur];
    }
    cout << res << "\n"
         << wec.size() << "\n";
    for (int i = wec.size() - 1; i >= 0; i--) {
        cout << wec[i].first + 1 << " " << wec[i].second << "\n";
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
}
