/*
Now playing:
Kavinsky - Odd Look [Kiss Land (Deluxe)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define pb push_back
#define ll long long
struct s {
    int id;
    vector<int> w;
};
bool comp(const s &a, const s &b) {
    return a.w < b.w;
}
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
vector<s> wec;
vector<vector<int>> wec1;
int pos[500'001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        wec.resize(n);
        wec1.resize(n + 1);
        droptop(1, n + 1)
        {
            int k;
            cin >> k;
            wec[i - 1].id = i;
            wec[i - 1].w.pb(i);
            wec1[i].pb(i);

            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                wec[i - 1].w.pb(x);
                wec1[i].pb(x);
            }

            sort(wec[i - 1].w.begin(), wec[i - 1].w.end());
        }
        hotbox(wec);
        int res = 0;
        droptop(0, n)
        {
            if (i == 0 or wec[i].w != wec[i - 1].w) {
                res++;
            }
            pos[wec[i].id] = res;
        }
        if (res == 1) {
            if (n == 1) {
                cout << 1 << "\n"
                     << 1 << "\n";
                return 0;
            } else {
                cout << 2 << "\n"
                     << 1 << " ";
                droptop(2, n + 1)
                cout << 2 << " ";
                cout << "\n1 2\n";
                return 0;
            }
        }
        cout << res << "\n";
        droptop(1, n + 1)
        {
            cout << pos[i] << " ";
        }
        cout << "\n";
        vector<pair<int, int>> road;
        droptop(1, n + 1)
        {
            int w = pos[i];
            for (int j : wec1[i]) {
                int ss = pos[j];
                if (ss == w)
                    continue;
                int a = min(w, ss), b = max(w, ss);
                road.pb({a, b});
            }
        }

        sort(road.begin(), road.end());
        auto it = unique(road.begin(), road.end());
        road.erase(it, road.end());

        for (const auto &ss : road) {
            cout << ss.first << " " << ss.second << "\n";
        }
    }
}
