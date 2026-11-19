/*
Now playing:

*/
#include <iostream>
#include <algorithm>
#include <stack>
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

ll cost[1'000'001];
ll dist[1'000'001];
ll suf[1'000'001];
int cheap[1'000'001];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int p, n;
        cin >> p >> n;
        droptop(i, 0, n)
        {
            cin >> cost[i] >> dist[i];
        }

        suf[n - 1] = dist[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] += suf[i + 1] + dist[i];
        }

        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (not s.empty() and cost[s.top()] >= cost[i]) {
                s.pop();
            }
            if (not s.empty()) {
                cheap[i] = s.top();
            } else {
                cheap[i] = -1;
            }
            s.push(i);
        }
        ll res = 0, cur = 0;
        droptop(i, 0, n)
        {
            int nxt = cheap[i];
            // droptop(j, i + 1, n)
            // {
            //     sum += dist[j - 1];
            //     if (sum > p)
            //         break;
            //     if (cost[j] < cost[i]) {
            //         nxt = j;
            //         break;
            //     }
            // }

            if (nxt != -1) {
                ll distcur = suf[i] - suf[nxt];
                if (distcur > p) {
                    nxt = -1;
                }
            }
            if (nxt == -1) {
                ll need = min((ll)p, suf[i]);
                if (cur < need) {
                    res += (need - cur) * cost[i];
                    cur = need;
                }
            } else {
                ll curdist = suf[i] - suf[nxt];
                if (cur < curdist) {
                    res += (curdist - cur) * cost[i];
                    cur = curdist;
                }
            }
            cur -= dist[i];
        }
        cout << res << "\n";
    }
}
