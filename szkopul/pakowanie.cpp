/*
Now playing:
Travis Scott - through the late night [Birds In The Trap Sing McKnight]
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
#define int ll

vector<int> wec[1'001];
int tab[1'001];
signed main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(i, 0, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
        }
        droptop(i, 0, 1'001)
        {
            hotbox(wec[i]);
        }
        int q;
        cin >> q;
        droptop(i, 0, q)
        {
            int a, b;
            cin >> a >> b;
            tab[a] += b;
        }

        int res = 0;
        droptop(i, 0, 1'001)
        {
            int cur = tab[i], idx = 0;
            while (cur > 0 and idx < wec[i].size()) {
                res += wec[i][idx], idx++, cur--;
            }
            if (cur > 0) {
                cout << "NIE\n";
                return 0;
            }
            vector<int> nw;
            while (idx + 1 < wec[i].size()) {
                nw.pb(wec[i][idx] + wec[i][idx + 1]);
                idx += 2;
            }
            if (not nw.empty() and i + 1 < 1001) {
                vector<int> lacz;
                lacz.reserve(wec[i + 1].size() + nw.size());
                int k = 0, j = 0;
                while (k < wec[i + 1].size() and j < nw.size()) {
                    if (wec[i + 1][k] <= nw[j]) {
                        lacz.pb(wec[i + 1][k++]);
                    } else {
                        lacz.pb(nw[j++]);
                    }
                }
                while (k < wec[i + 1].size())
                    lacz.pb(wec[i + 1][k++]);
                while (j < nw.size())
                    lacz.pb(nw[j++]);
                wec[i + 1] = move(lacz);
            }
        }
        cout << res;
    }
}
