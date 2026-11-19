/*
Now playing:
21 Savage - Rap Saved Me (feat. Quavo) [Without Warning]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define cll constexpr long long
#define cint constexpr int
#define int long long
vector<int> wec[500'001];
int sub[500'001];
bool wiz[500'001];
bool wizb[500'001];
vector<int> dist1, dist2;
int closest[500'001];
vector<int> centroid;
int cur = 0;
ll res = 0;
bool comp(int a, int b) {
    return a < b;
}
int dfs(int w, int p = -1) {
    sub[w] = 1;
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        sub[w] += dfs(ss, w);
    }
    return sub[w];
}
struct s {
    int siz;
    vector<int> tree;
    void init(int n) {
        siz = n + 2;
        tree.resize(siz + 1);
    }
    void add(int i, int war) {
        for (; i <= siz; i += i & -i) {
            tree[i] += war;
        }
    }
    int zap(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
    int zap(int a, int b) {
        if (a > b)
            return 0;
        return zap(b) - zap(a - 1);
    }
} a1, a2, b1, b2;
void dst(int w, vector<int> &dist, int p = -1) {
    for (int ss : wec[w]) {
        if (ss == p)
            continue;
        dist[ss] = dist[w] + 1;
        dst(ss, dist, w);
    }
}
ll ansa(int w, int n) {
    if (centroid.size() == 1) {
        int odl = dist1[w];
        return b1.zap(odl + 1, n + 1);
    }
    int cent = closest[w];
    if (cent == 1) {
        int odl = dist1[w];
        ll curres = 0;
        curres += b1.zap(odl + 1, n + 1);
        curres += b2.zap(odl + 2, n + 1);
        return curres;
    }
    int odl = dist2[w];
    ll curres = 0;
    curres += b2.zap(odl + 1, n + 1);
    curres += b1.zap(odl + 2, n + 1);
    return curres;
}
ll ansb(int w, int n) {
    if (centroid.size() == 1) {
        int odl = dist1[w];
        return a1.zap(1, odl + 1);
    }
    int cent = closest[w];
    if (cent == 1) {
        int odl = dist1[w];
        ll curres = 0;
        curres += a1.zap(1, odl + 1);
        curres += a2.zap(1, odl);
        return curres;
    }
    int odl = dist2[w];
    ll curres = 0;
    curres += a2.zap(1, odl + 1);
    curres += a1.zap(1, odl);
    return curres;
}
ll bins(int w, const vector<int> &l, const vector<int> &r) {
    int odl;
    int cen;
    if (centroid.size() == 1) {
        odl = dist1[w];
        return l.end() - lower_bound(l.begin(), l.end(), odl);
    }
    cen = closest[w];
    if (cen == 0)
        odl = dist1[w];
    else if (cen == 1)
        odl = dist2[w];
    else
        odl = dist1[w];
    ll res = 0;
    res += l.end() - upper_bound(l.begin(), l.end(), odl);
    res += r.end() - upper_bound(r.begin(), r.end(), odl);

    if (cen == 1) {
        res += upper_bound(l.begin(), l.end(), odl) - lower_bound(l.begin(), l.end(), odl);
    } else if (cen == 2) {
        res += upper_bound(r.begin(), r.end(), odl) - lower_bound(r.begin(), r.end(), odl);
    }

    return res;
}
signed main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;

        droptop(1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].push_back(b);
            wec[b].push_back(a);
        }
        dfs(1);
        droptop(1, n + 1)
        {
            int makssub = n - sub[i];
            for (int ss : wec[i]) {
                if (sub[ss] < sub[i])
                    makssub = max(makssub, sub[ss]);
            }
            if (makssub <= (n >> 1)) {
                centroid.push_back(i);
            }
        }
        if (centroid.size() == 1) {
            dist1.resize(n + 1);
            dist1[centroid[0]] = 0;
            dst(centroid[0], dist1);
            droptop(1, n + 1)
            {
                closest[i] = 1;
            }
        } else {
            dist1.resize(n + 1);
            dist2.resize(n + 1);
            dist1[centroid[0]] = 0;
            dst(centroid[0], dist1);
            dist2[centroid[1]] = 0;
            dst(centroid[1], dist2);
            droptop(1, n + 1)
            {
                if (dist1[i] <= dist2[i])
                    closest[i] = 1;
                else
                    closest[i] = 2;
            }
        }
        a1.init(n), a2.init(n), b1.init(n), b2.init(n);
        int sa, sb, q;
        cin >> sa >> sb >> q;
        vector<int> a(sa), b(sb);
        ll twinz = 0;
        droptop(0, sa)
        {
            cin >> a[i];
            wiz[a[i]] = true;
        }
        droptop(0, sb)
        {
            cin >> b[i];
            wizb[b[i]] = true;
            if (wiz[b[i]])
                twinz++;
        }
        for (int w : b) {
            int odl = (closest[w] == 1) ? dist1[w] : dist2[w];
            if (closest[w] == 1) {
                b1.add(odl + 1, 1);
            } else {
                b2.add(odl + 1, 1);
            }
        }
        for (int w : a) {
            res += ansa(w, n);
            int odl = (closest[w] == 1) ? dist1[w] : dist2[w];
            if (closest[w] == 1) {
                a1.add(odl + 1, 1);
            } else {
                a2.add(odl + 1, 1);
            }
        }
        cout << res - twinz << "\n";
        // vector<int> l, r, centr;
        // for (int w : b) {
        //     if (closest[w] == 1) {
        //         l.pb(dist1[w]);
        //     } else {
        //         r.pb(dist1[w]);
        //     }
        // }
        // hotbox(l);
        // hotbox(r);
        // for (int w : a) {
        //     res += bins(w, l, r);
        // }
        cookie(q)
        {
            char c, z;
            int x;
            cin >> c >> z >> x;
            int odl = (closest[x] == 1) ? dist1[x] : dist2[x];
            if (c == 'A') {
                if (z == '+') {
                    res += ansa(x, n);
                    wiz[x] = true;
                    if (wizb[x])
                        twinz++;
                    if (closest[x] == 1) {
                        a1.add(odl + 1, 1);
                    } else {
                        a2.add(odl + 1, 1);
                    }
                } else {
                    if (closest[x] == 1) {
                        a1.add(odl + 1, -1);
                    } else {
                        a2.add(odl + 1, -1);
                    }
                    res -= ansa(x, n);
                    wiz[x] = false;
                    if (wizb[x])
                        twinz--;
                }
            } else {
                if (z == '+') {
                    res += ansb(x, n);
                    wizb[x] = true;
                    if (wiz[x])
                        twinz++;
                    if (closest[x] == 1) {
                        b1.add(odl + 1, 1);
                    } else {
                        b2.add(odl + 1, 1);
                    }
                } else {
                    if (closest[x] == 1) {
                        b1.add(odl + 1, -1);
                    } else {
                        b2.add(odl + 1, -1);
                    }
                    res -= ansb(x, n);
                    wizb[x] = false;
                    if (wiz[x])
                        twinz--;
                }
            }
            cout << res - twinz << "\n";
        }
    }
    return 0;
}
