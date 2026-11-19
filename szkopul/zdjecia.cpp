/*
Now playing:
Future - Hard Work Pays Off [Future and Juice WRLD Present... WRLD ON DRUGS]
*/
#include <iostream>
#include <algorithm>
#include <queue>
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

vector<int> wec[500'001];
int in[500'001];
int total = 0;
int res[500'001];

bool wiz[500'001];

// void dfs(int w) {
//     wiz[w] = true;
//     for (int ss : wec[w]) {
//         if (wiz[ss])
//             continue;
//         dfs(ss);
//     }
// }
// bool ssc(int n) {
//     int cnt = 0;
//     droptop(i, 1, n + 1)
//     {
//         if (wiz[i] or wec[i].size() == 0)
//             continue;
//         dfs(i);
//         if (++cnt > 1)
//             return false;
//     }
//     return true;
// }

vector<int> ord;

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        droptop(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            wec[b].pb(a);
        }

        if (m == 0) {
            cout << "TAK\n";
            droptop(i, 1, n + 1)
            {
                cout << i << " ";
            }
            return 0;
        }
        // if (not ssc(n)) {
        //     cout << "NIE\n";
        //     return 0;
        // }

        queue<int> q;
        wiz[1] = true;
        q.push(1);

        while (not q.empty()) {
            int w = q.front();
            q.pop();
            ord.pb(w);

            for (int ss : wec[w]) {
                if (wiz[ss])
                    continue;

                in[ss]++, total++;

                if (ss != 2 and in[ss] == (wec[ss].size() >> 1)) {
                    wiz[ss] = true;
                    q.push(ss);
                }
            }
        }

        if (wiz[2]) {
            ord.pb(2);
            wiz[2] = true;
        }

        if (total != m) {
            cout << "NIE\n";
            return 0;
        }

        droptop(i, 3, n + 1)
        {
            if (wec[i].size() > 0 and in[i] != (wec[i].size() >> 1)) {
                cout << "NIE\n";
                return 0;
            }
        }

        droptop(i, 1, n + 1)
        {
            if (not wiz[i]) {
                ord.pb(i);
                wiz[i] = true;
            }
        }

        if (ord.size() != n) {
            cout << "NIE\n";
            return 0;
        }

        cout << "TAK\n";
        droptop(i, 0, n)
        {
            res[ord[i]] = i + 1;
        }

        droptop(i, 1, n + 1)
        {
            cout << res[i] << " ";
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
