/*
Now playing:
Artemas - superstar [LOVERCORE]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> pos[500'001];
const int base = (1 << 19);
pair<int, int> tree[base << 1];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    if (a.second == 0)
        return b;
    if (b.second == 0)
        return a;

    if (a.first == b.first)
        return {a.first, a.second + b.second};
    else if (a.second > b.second)
        return {a.first, a.second - b.second};
    else
        return {b.first, b.second - a.second};
}

pair<int, int> upd(int w) {
    if (w >= base)
        return tree[w];
    auto a = upd(w << 1), b = upd(w << 1 | 1);
    tree[w] = merge(a, b);
    // if (a.first == b.first)
    //     tree[w] = {a.first, a.second + b.second};
    // else if (a.second > b.second)
    //     tree[w] = {a.first, a.second - b.second};
    // else
    //     tree[w] = {b.first, b.second - a.second};
    return tree[w];
}

pair<int, int> query(int w, int l, int r, int a, int b) {
    if (r < a or b < l)
        return {0, 0};
    if (a <= l and r <= b)
        return tree[w];

    int mid = l + ((r - l) >> 1);
    auto a1 = query(w << 1, l, mid, a, b), b1 = query(w << 1 | 1, mid + 1, r, a, b);
    return merge(a1, b1);

    // if (a1.first == b1.first)
    //     return {a1.first, a1.second + b1.second};
    // else if (a1.second > b1.second)
    //     return {a1.first, a1.second - b1.second};
    // else
    //     return {b1.first, b1.second - a1.second};
}

int f(const int &n) {
    int l, r;
    cin >> l >> r;

    auto [w, cnt] = query(1, 0, base - 1, l - 1, r - 1);
    if (cnt == 0)
        return 0;
    return (upper_bound(pos[w].begin(), pos[w].end(), r - 1) - lower_bound(pos[w].begin(), pos[w].end(), l - 1) > ((r - l + 1) >> 1) ? w : 0);
    return 0;
}

signed main() {
    raindrop;
    int n, t = 1;
    cin >> n >> t;
    droptop(i, 0, n)
    {
        cin >> tree[i + base].first, tree[i + base].second = 1, pos[tree[i + base].first].pb(i);
    }

    upd(true);

    while (t--) {
        cout << f(n) << "\n";
    }
    return 0;
}
