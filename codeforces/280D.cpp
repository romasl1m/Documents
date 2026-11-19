/*
Now playing:
Offset - Different Species (feat. Gunna) [KIARI]
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
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

// const int base = 100'001;
const int base = (1 << 17);
struct node {
    int dp[21][2][2];
};

node nullnode;

int tab[base];
node tree[base << 1];

node merge(const node &l, const node &r, const int &k) {
    node res = nullnode;
    droptop(fulll, 0, k + 1)
    {
        droptop(prefl, 0, 2)
        {
            droptop(sufl, 0, 2)
            {
                int leftside = l.dp[fulll][prefl][sufl];
                if (leftside <= -1e9)
                    continue;

                droptop(prefr, 0, 2)
                {
                    int intersection2 = (sufl & prefr);
                    // int intersection = (sufl == 1 and prefr == 1 ? 1 : 0), // suffix of the left child links up with prefix of the right one makin one segment.

                    int limit = k - fulll + intersection2;
                    droptop(fullr, 0, limit + 1)
                    {
                        droptop(sufr, 0, 2)
                        {
                            int rightside = r.dp[fullr][prefr][sufr];
                            if (rightside <= -1e9)
                                continue;
                            // if (r.dp[fullr][prefr][sufr] <= -1e9)
                            //     continue;

                            int segments = fulll + fullr - intersection2;
                            // if (segments <= k) {
                            //     int cur = l.dp[fulll][prefl][sufl] + r.dp[fullr][prefr][sufr];
                            //     res.dp[segments][prefl][sufr] = max(res.dp[segments][prefl][sufr], cur);
                            // }
                            int cur = leftside + rightside;
                            if (cur > res.dp[segments][prefl][sufr])
                                res.dp[segments][prefl][sufr] = cur;
                        }
                    }
                }
            }
        }
    }
    return res;
}

void init(int pos, int war) {
    tree[pos] = nullnode;
    tree[pos].dp[1][1][1] = war, tree[pos].dp[0][0][0] = 0;
}

void upd(int w, int war, const int &k) {
    tab[w] = war, w += base, init(w, war),
    w >>= 1;
    while (w >= 1) {
        tree[w] = merge(tree[w << 1], tree[w << 1 | 1], k);
        w >>= 1;
    }
}

// node query(int w, int l, int r, int a, int b, int k) {
//     if (r < a or l > b) {
//         return nullnode;
//     }
//     if (a <= l and r <= b)
//         return tree[w];
//
//     int mid = l + ((r - l) >> 1);
//     return merge(query(w << 1, l, mid, a, b, k), query(w << 1 | 1, mid + 1, r, a, b, k), k);
// }
node query(int l, int r, int k) {
    l += base, r += base;
    node resl = nullnode, resr = nullnode;
    bool gotl = false, gotr = false;

    while (l <= r) {
        if (l & 1) {
            if (not gotl)
                resl = tree[l], gotl = true;
            else
                resl = merge(resl, tree[l], k);
            l++;
        }
        if (not(r & 1)) {
            if (not gotr)
                resr = tree[r], gotr = true;
            else
                resr = merge(tree[r], resr, k);
            r--;
        }
        l >>= 1, r >>= 1;
    }

    if (gotl and gotr)
        return merge(resl, resr, k);
    if (gotl)
        return resl;
    if (gotr)
        return resr;
    return nullnode;
}

void f() {
    int n;
    cin >> n;
    droptop(i, 0, 21)
    {
        nullnode.dp[i][0][0] = nullnode.dp[i][0][1] = nullnode.dp[i][1][0] = nullnode.dp[i][1][1] = -2e9;
    }
    nullnode.dp[0][0][0] = 0;

    droptop(i, 1, base << 1)
    {
        tree[i] = nullnode;
    }

    droptop(i, 0, n)
    {
        cin >> tab[i];
        init(i + base, tab[i]);
    }
    for (int i = base - 1; i > 0; i--) {
        tree[i] = merge(tree[i << 1], tree[i << 1 | 1], 20);
    }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (not x) {
            int pos, cur;
            cin >> pos >> cur;
            tab[pos - 1] = cur;
            upd(pos - 1, cur, 20);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            // node res = query(1, 0, base - 1, l - 1, r - 1, k);
            node res = query(l - 1, r - 1, k);
            int ans = -2e9;

            droptop(kk, 0, k + 1)
            {
                droptop(i, 0, 2)
                {
                    droptop(j, 0, 2)
                    {
                        ans = max(ans, res.dp[kk][i][j]);
                    }
                }
            }

            cout << max(0, ans) << "\n";
        }
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
