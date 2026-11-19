/*
Now playing:
Diplo - BRAIN (feat. Artemas) [BRAIN (feat. Artemas)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long
#define int ll

int tab[300'001];
int old[300'001];
vector<pair<pair<int, int>, int>> wec;
bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first > b.first.first;
}

int f() {
    int n, m;
    cin >> n >> m;
    wec.resize(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
    }
    droptop(i, 0, n)
    {
        int x;
        cin >> x;
        old[i] = x;
        wec[i].first = {tab[i], x}, wec[i].second = i;
    }
    sort(hotbox(wec), comp);

    droptop(i, 0, m)
    {
        multiset<int> s;
        droptop(j, 0, n)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        droptop(j, 0, n)
        {
            auto it = s.lower_bound(wec[j].first.second);
            if (it == s.end()) {
                cout << "NIE";
                return 0;
            }
            wec[j].first.second = *it;
            s.erase(it);
        }
    }

    ll res = 0;
    droptop(i, 0, n)
    {
        // cerr << wec[i].first << " " << wec[i].second << endl;
        res += (ll)wec[i].first.first * (ll)(wec[i].first.second - old[wec[i].second]);
    }
    cout << res;
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
