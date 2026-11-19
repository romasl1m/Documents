/* Now playing:
Molly Santana - So Right [Molly Santana]
*/
#include <iostream>
#include <vector>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int tab[100'001];
int pos[50'001];
const int base = (1 << 17);
int tree[base << 1];

void add(int pos, int x = 1) {
    pos += base;
    tree[pos] += x;
    pos >>= 1;
    while (pos >= 1) {
        tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
        pos >>= 1;
    }
}

int sum(int w, int l, int r, int a, int b) {
    if (r < a or b < l)
        return 0;
    if (a <= l and r <= b)
        return tree[w];
    int mid = (l + r) >> 1;
    return sum(w << 1, l, mid, a, b) + sum(w << 1 | 1, mid + 1, r, a, b);
}

vector<int> res;
int main() {
    raindrop;
    int t = 1;
    res.reserve(1'000'001);
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(i, 1, n << 1 | 1)
        {
            cin >> tab[i];
            if (pos[tab[i]] == 0)
                pos[tab[i]] = i;
        }

        droptop(i, 1, n << 1 | 1)
        {
            if (pos[tab[i]] == i)
                continue;
            int p1 = pos[tab[i]], p2 = i, rm1 = sum(1, 0, base - 1, 1, p1 - 1), rm2 = sum(1, 0, base - 1, 1, p2 - 1);
            p1 -= rm1, p2 -= rm2;
            for (int j = p2 - 1; j >= p1 + 1; j--) {
                res.pb(j);
            }
            add(pos[tab[i]], 1);
            add(i, 1);
        }
        cout << res.size() << "\n";
        for (int x : res)
            cout << x << "\n";
    }
}
