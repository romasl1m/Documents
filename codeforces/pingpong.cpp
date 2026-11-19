/*
Now playing:
Lil Peep - girls [HELLBOY]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

int res[200'002], lst[200'002], cur[200'002], bestwar[200'002], bestp[200'002], win[200'002], par[200'002], wec[200'002][2];

int f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 1, m + 1)
    {
        int x, y;
        cin >> x >> y;
        if (lst[x])
            par[lst[x]] = i;
        if (lst[y])
            par[lst[y]] = i;
        wec[i][false] = lst[x], wec[i][true] = lst[y], lst[y] = 0, lst[x] = i, win[i] = x;
    }
    vector<int> st;
    droptop(i, 0, n)
    {
        if (lst[i])
            par[lst[i]] = m + 1, st.pb(lst[i]);
    }

    int curbestwar = 0, curbestp = -1;
    while (not st.empty()) {
        int w = st.back();
        st.pop_back();
        if (w > 0) {
            int winner = win[w];
            bestwar[w] = curbestwar, bestp[w] = curbestp, cur[winner] += par[w] - w;
            if (curbestwar < cur[winner] or (cur[winner] == curbestwar and winner < bestp[w]))
                curbestwar = cur[winner], curbestp = winner;
            res[curbestp]++, st.pb(-w);
            for (int ss : wec[w])
                if (ss)
                    st.pb(ss);
        } else
            w = -w, cur[win[w]] -= par[w] - w, curbestwar = bestwar[w], curbestp = bestp[w];
    }
    droptop(i, 0, n)
    {
        cout << res[i] << " ";
    }

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
