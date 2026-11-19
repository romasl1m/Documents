#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
const int N = 1'000'001;
long long int BIT[N];
long long int SUM[N];
vector<long long> comp;
vector<pair<bool, pair<long long, long long>>> zap;
int tab[N];
// int sum[N << 1];
void update(int w, long long int war, bool count) {
    w++;
    if (not count) {
        while (w < N) {
            SUM[w] += war;
            w += (w & -w);
        }
        return;
    }
    while (w < N) {
        BIT[w] += war;
        w += (w & -w);
    }
}
int idx(long long x) {
    return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}

long long int query(int w, bool count) {
    w++;
    long long int res = 0;
    if (not count) {
        while (w > 0) {
            res += SUM[w];
            w -= (w & -w);
        }
        return res;
    }
    while (w > 0) {
        res += BIT[w];
        w -= (w & -w);
    }
    return res;
}

int main() {
    raindrop;
    int n, m;
    cin >> n >> m;
    zap.resize(m);
    long long int total = 0;
    droptop(0, m)
    {
        char c;
        cin >> c;
        long long int a, b;
        cin >> a >> b;
        zap[i] = {c == 'U', {a, b}};
        if (c == 'U') {
            comp.push_back(b);
            // tab[a] = b;
            // update(a,-1,true);
            // update(a,-a,false);
            // update(b, 1, true);
            // update(b,b,false);
            //
            // long long old = tab[a];
            // if (old > 0) {
            //     update(old, -1, true);
            //     update(old, -old, false);
            // }
            // tab[a] = b;
            // if (b > 0) {
            //     update(b, 1, true);
            //     update(b, b, false);
            // }
            //
            // if (old == 0 and b != 0)
            //     total++;
            // if (old != 0 and b == 0)
            //     total--;
        } else {
        }
    }
    // hotbox(comp);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    droptop(0, m)
    {
        auto [a, b] = zap[i].second;
        if (zap[i].first) {
            int old = tab[a];
            if (old > 0) {
                int p = idx(old);
                update(p, -1, true);
                update(p, -old, false);
            }
            tab[a] = b;
            if (b > 0) {
                int p = idx(b);
                update(p, 1, true), update(p, b, false);
            }
            if (old == 0 and b != 0)
                total++;
            if (old != 0 and b == 0)
                total--;
        } else {
            int p = lower_bound(comp.begin(), comp.end(), b) - comp.begin();
            long long int small = query(p - 1, false);
            long long int large = total - query(p - 1, true);
            if (small + large * b >= a * b) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        }
    }
}
