/*
Now playing:
Huncho Jack - Saint Laurent Mask [Huncho Jack, Jack Huncho]
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

pair<int, int> check(const vector<int> &joined, const vector<vector<int>> &wec) {
    int lim = min((int)joined.size(), 5);
    droptop(i, 0, lim)
    {
        droptop(j, i + 1, joined.size())
        {
            if (not binary_search(wec[joined[i]].begin(), wec[joined[i]].end(), joined[j])) {
                return {joined[i], joined[j]};
            }
        }
    }
    return {-1, -1};
}
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> wec(n + 1);
        vector<pair<int, int>> road(m);
        droptop(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b);
            wec[b].pb(a);
            road[i] = {a, b};
        }
        droptop(i, 1, n + 1)
        {
            hotbox(wec[i]);
        }

        bool ready = false;
        droptop(i, 0, m)
        {
            if (ready)
                break;
            auto [a, b] = road[i];
            int k = 0, j = 0;
            vector<int> joined;
            while (k < wec[a].size() and j < wec[b].size()) {
                if (wec[a][k] == wec[b][j]) {
                    if (joined.size() < 15) {
                        joined.pb(wec[a][k]);
                    }
                    k++, j++;
                } else if (wec[a][k] < wec[b][j]) {
                    k++;
                } else {
                    j++;
                }
            }
            if (joined.size() < 2)
                continue;

            auto cur = check(joined, wec);
            if (cur.first == -1)
                continue;
            cout << "TAK\n";
            ready = true;
            cout << a << " " << b << " " << cur.first << " " << cur.second << "\n";
        }
        if (not ready)
            cout << "NIE\n";
    }
}
