#include <iostream>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
vector<pair<int, int>> wec[1'000'001];
int siz[1'000'001];
int tab[1'000'001];
bool color[1'000'001];
long long int res = 0;
int n;
void subs(int w, int p) {
    siz[w] = 1;
    int k = 0;
    vector<int> ks;
    for (auto [ss, i] : wec[w]) {
        if (ss == p)
            continue;
        subs(ss, w);
        siz[w] += siz[ss];
        long long sum = siz[ss], czar = (sum >> 1), bial = (sum - czar);
        res += czar * ((n >> 1) - czar) + bial * ((n >> 1) - bial);
        if (siz[ss] % 2 == 1) {
            k++;
            ks.push_back(ss);
        }
    }
    int flip;
    if (k % 2 == 0) {
        flip = k >> 1;
    } else {
        flip = ((k + 1) >> 1);
    }
    droptop(0, flip)
    {
        tab[ks[i]] = true;
    }
}
void dfs(int w, int p, int cur) {
    color[w] = cur;
    for (auto [ss, i] : wec[w]) {
        if (ss == p)
            continue;
        dfs(ss, w, cur ^ tab[ss]);
    }
}
int main() {
    cin >> n;
    droptop(1, n)
    {
        int a, b;
        cin >> a >> b;
        wec[a].push_back({b, i});
        wec[b].push_back({a, i});
    }
    subs(1, -1);
    dfs(1, -1, false);
    cout << res << "\n";
    droptop(1, n + 1)
    {
        cout << color[i];
    }
}
