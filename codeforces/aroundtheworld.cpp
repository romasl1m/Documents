#include <iostream>
#include <vector>
#include <map>
#include <cstdint>
using namespace std;
using space = uint32_t;
const int mod = 1e9 + 7;
vector<pair<int, int>> wec[100'001];
vector<int> ssc[100'001];
bool wiz[100'001];
int which[100'001];
vector<pair<int, int>> from1[100'001];
map<space, long long> dp, newdp;
vector<space> opt[100'001];

void dfs(int w, int ssccount) {
    wiz[w] = true;
    which[w] = ssccount;
    ssc[ssccount].push_back(w);
    for (auto [ss, cost] : wec[w]) {
        if (wiz[ss] or ss == 1)
            continue;
        dfs(ss, ssccount);
    }
}

vector<int> cycles;
int xr[100'001];
void dfscycle(int w, int comp, int p = -1) {
    wiz[w] = true;
    for (auto [ss, cost] : wec[w]) {
        if (ss == 1 or ss == p or which[ss] != comp)
            continue;
        if (not wiz[ss]) {
            xr[ss] = xr[w] ^ cost;
            dfscycle(ss, comp, w);
        } else {
            if (w <= ss)
                continue;
            int cycle = xr[w] ^ xr[ss] ^ cost;
            cycles.push_back(cycle);
        }
    }
}

vector<int> makelin(const vector<int> &cycles) {
    vector<int> base(5, 0);
    bool ok = true;
    for (int x : cycles) {
        int y = x;
        for (int i = 4; i >= 0; i--) {
            if (not(y & (1 << i)))
                continue;
            if (not base[i]) {
                base[i] = y;
                y = -1;
                break;
            }
            y ^= base[i];
        }
        if (y == 0) {
            return {};
        }
    }
    return base;
}
space genmask(const vector<int> &base) {
    vector<int> war = {0};
    for (int i = 0; i < 5; i++) {
        if (not base[i])
            continue;
        int sz = war.size();
        for (int j = 0; j < sz; j++) {
            war.push_back(war[j] ^ base[i]);
        }
    }
    space mask = 0;
    for (int x : war) {
        mask |= (1u << x);
    }
    return mask;
}

space add_space(space a, space b) {
    if (a == 1)
        return b;
    if (b == 1)
        return a;
    space res = 0;
    for (int i = 0; i < 32; i++) {
        if (not(a & (1u << i)))
            continue;
        for (int y = 0; y < 32; y++) {
            if (not(b & (1u << y)))
                continue;
            res |= (1u << (i ^ y));
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        wec[a].push_back({b, w});
        wec[b].push_back({a, w});
    }
    // countin' sscs
    int ssccount = 0;
    wiz[1] = true;
    for (auto [ss, cost] : wec[1]) {
        if (wiz[ss]) {
            from1[which[ss]].push_back({ss, cost});
            continue;
        }
        ssccount++;
        from1[ssccount].push_back({ss, cost});
        dfs(ss, ssccount);
    }
    // simple cycles and
    // making a linear space
    for (int i = 1; i <= ssccount; i++) {
        int k = from1[i].size();
        cycles.clear();
        for (int w : ssc[i])
            wiz[w] = false;
        int w = ssc[i][0];
        xr[w] = 0;
        dfscycle(w, i);

        for (int mask = 0; mask < (1 << k); mask++) {
            vector<int> cur;
            if (mask > 0)
                cur = cycles;
            if (k == 2 and mask == 3) {
                auto [a, cost1] = from1[i][0];
                auto [b, cost2] = from1[i][1];
                int cycl = xr[a] ^ xr[b] ^ cost1 ^ cost2;
                cycl %= mod;
                cur.push_back(cycl);
            }
            vector<int> base = makelin(cur);
            if (base.empty() and not cur.empty())
                continue;
            opt[i].push_back(genmask(base));
        }
    }

    // dp
    dp[1] = 1;
    for (int i = 1; i <= ssccount; i++) {
        newdp.clear();
        for (space x : opt[i]) {
            for (auto [y, res] : dp) {
                if ((x & y) != 1)
                    continue;
                // if((x & y) == 1){
                space z = add_space(x, y);
                newdp[z] += res;
                newdp[z] %= mod;
                // }
            }
        }
        dp = newdp;
    }
    long long res = 0;
    for (auto [x, cur] : dp) {
        res += cur;
        res %= mod;
    }
    cout << res;
    return 0;
}
