/*
Now playing:
Trippie Redd - SWAGGER [SWAGGER]
*/
#include <iostream>
#include <algorithm>
#include <set>
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
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<int> wec(m);
        set<int> res;

        droptop(i, 0, m)
        {
            cin >> wec[i];
            res.insert(wec[i]);
        }

        int cur = 1;
        droptop(i, 0, n)
        {
            cur++;
            if (s[i] == 'B') {
                while (res.count(cur))
                    cur++;
            }
            res.insert(cur);
            if (s[i] == 'B') {
                while (res.count(cur)) {
                    cur++;
                }
            }
        }

        cout << res.size() << "\n";
        for (const auto &x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
