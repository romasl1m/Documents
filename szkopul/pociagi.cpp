/*
Now playing:
Juice WRLD - Come and Go (with Marshmello) [Legends Never Die]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 9;

ll base[1'01];
ll base1[1'01];
string tab[1'001];
string orig[1'001];
int res[1'001];
vector<int> zap[100'001];

int enter[1'001];

struct hashs {
    ll h1, h2;
    bool operator==(const hashs &other) const {
        return h1 == other.h1 and h2 == other.h2;
    }
};

struct hasher {
    size_t operator()(const hashs &k) const {
        return (k.h1 << 32) ^ k.h2;
    }
};

hashs hasz[1'001];
hashs grouphash[1'001];
unordered_map<hashs, vector<pair<int, int>>, hasher> mapa;
unordered_map<hashs, vector<int>, hasher> seg;

hashs hashf(const string &s, const int &n) {
    ll res = 0, res1 = 0;
    droptop(i, 0, s.length())
    {
        res = (res + base[i] * (s[i] - 'a')) % mod;
        res1 = (res1 + base1[i] * (s[i] - 'a')) % mod1;
    }
    return {res, res1};
}

void init() {
    base[0] = base1[0] = 1;
    droptop(i, 1, 100)
    {
        base[i] = (base[i - 1] * 31) % mod;
        base1[i] = (base1[i - 1] * 37) % mod1;
    }
}

int buildf(int w, int l, int r, const vector<pair<int, int>> &wec, vector<int> &tree) {
    if (l == r) {
        tree[w] = wec[l].second;
        return tree[w];
    }
    int mid = l + ((r - l) >> 1);
    tree[w] = max(buildf(w << 1, l, mid, wec, tree), buildf(w << 1 | 1, mid + 1, r, wec, tree));
    return tree[w];
}

int maks(int w, int l, int r, int a, int b, const vector<int> &tree) {
    if (r < a or l > b)
        return 0;
    if (a <= l and r <= b) {
        return tree[w];
    }
    int mid = l + ((r - l) >> 1);
    return max(maks(w << 1, l, mid, a, b, tree), maks(w << 1 | 1, mid + 1, r, a, b, tree));
}

void f(int p, int cur) {
    hashs h = grouphash[p];
    const auto &wec = mapa[h];
    int siz = wec.size();
    if (siz == 0)
        return;
    int start = enter[p];
    auto itl = lower_bound(wec.begin(), wec.end(), make_pair(start, (int)-2e9));
    auto itr = upper_bound(wec.begin(), wec.end(), make_pair(cur, (int)2e9));
    int l = itl - wec.begin(), r = itr - wec.begin() - 1;
    if (l <= r and l < siz and r >= 0) {
        int curmaks = maks(1, 0, siz - 1, l, r, seg[h]);
        res[p] = max(res[p], curmaks);
    }
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        init();
        int n, l, m;
        if (!(cin >> n >> l >> m))
            return 0;

        droptop(i, 0, n)
        {
            string s;
            cin >> s;
            tab[i] = s;
            orig[i] = s;
            hasz[i] = hashf(s, n);
            mapa[hasz[i]].pb({0, 1});
            grouphash[i] = hasz[i];
        }

        droptop(i, 1, m + 1)
        {
            int p1, w1, p2, w2;
            cin >> p1 >> w1 >> p2 >> w2;
            zap[i] = {p1, w1, p2, w2};

            p1--, w1--, p2--, w2--;
            if (p1 == p2) {
                mapa[hasz[p1]].pb({i, -1});
            } else {
                mapa[hasz[p1]].pb({i, -1}), mapa[hasz[p2]].pb({i, -1});
            }
            char c1 = tab[p1][w1];
            char c2 = tab[p2][w2];

            swap(tab[p1][w1], tab[p2][w2]);

            hasz[p1].h1 = (hasz[p1].h1 + 1LL * (c2 - c1) * base[w1]) % mod;
            hasz[p1].h2 = (hasz[p1].h2 + 1LL * (c2 - c1) * base1[w1]) % mod1;

            if (hasz[p1].h1 < 0)
                hasz[p1].h1 += mod;
            if (hasz[p1].h2 < 0)
                hasz[p1].h2 += mod1;

            hasz[p2].h1 = (hasz[p2].h1 + 1LL * (c1 - c2) * base[w2]) % mod;
            hasz[p2].h2 = (hasz[p2].h2 + 1LL * (c1 - c2) * base1[w2]) % mod1;

            if (hasz[p2].h1 < 0)
                hasz[p2].h1 += mod;
            if (hasz[p2].h2 < 0)
                hasz[p2].h2 += mod1;

            if (p1 == p2) {
                mapa[hasz[p1]].pb({i, 1});
            } else {
                mapa[hasz[p1]].pb({i, 1}), mapa[hasz[p2]].pb({i, 1});
            }
        }

        for (auto &[h, wec] : mapa) {
            int cur = 0;
            for (auto &[czas, plmin] : wec) {
                cur += plmin;
                plmin = cur;
            }

            seg[h].resize(wec.size() << 2);
            buildf(1, 0, wec.size() - 1, wec, seg[h]);
        }

        droptop(i, 0, n)
        {
            tab[i] = orig[i];
        }

        droptop(i, 1, m + 1)
        {
            int p1 = zap[i][0] - 1;
            int w1 = zap[i][1] - 1;
            int p2 = zap[i][2] - 1;
            int w2 = zap[i][3] - 1;

            f(p1, i - 1);
            if (p1 != p2) {
                f(p2, i - 1);
            }

            char c1 = tab[p1][w1], c2 = tab[p2][w2];
            swap(tab[p1][w1], tab[p2][w2]);

            grouphash[p1].h1 = (grouphash[p1].h1 + 1LL * (c2 - c1) * base[w1]) % mod;
            grouphash[p1].h2 = (grouphash[p1].h2 + 1LL * (c2 - c1) * base1[w1]) % mod1;
            if (grouphash[p1].h1 < 0)
                grouphash[p1].h1 += mod;
            if (grouphash[p1].h2 < 0)
                grouphash[p1].h2 += mod1;

            grouphash[p2].h1 = (grouphash[p2].h1 + 1LL * (c1 - c2) * base[w2]) % mod;
            grouphash[p2].h2 = (grouphash[p2].h2 + 1LL * (c1 - c2) * base1[w2]) % mod1;
            if (grouphash[p2].h1 < 0)
                grouphash[p2].h1 += mod;
            if (grouphash[p2].h2 < 0)
                grouphash[p2].h2 += mod1;

            enter[p1] = enter[p2] = i;
        }

        droptop(i, 0, n)
        {
            f(i, m);
        }

        droptop(i, 0, n)
        {
            cout << res[i] << "\n";
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
