#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int base = 1 << 17;
int tree[base << 1];
int lazy[base << 1];
int a[base + 1];
int b[base + 1];
vector<vector<int>> change;
void push(int w) {
    if (tree[w] == 0)
        return;
    tree[w << 1] = tree[w];
    tree[w << 1 | 1] = tree[w];
    tree[w] = 0;
}
void upd(int w, int l, int r, int a1, int b1, int id) {
    if (a1 <= l and r <= b1) {
        tree[w] = id;
        return;
    }
    push(w);
    int mid = (l + r) >> 1;
    if (a1 <= mid)
        upd(w << 1, l, mid, a1, b1, id);
    if (b1 > mid)
        upd(w << 1 | 1, mid + 1, r, a1, b1, id);
}
int zap(int w, int l, int r, int i) {
    if (l == r)
        return tree[w];
    push(w);
    int mid = (l + r) >> 1;
    if (i > mid) {
        return zap(w << 1 | 1, mid + 1, r, i);
    } else {
        return zap(w << 1, l, mid, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    change.resize(m + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    change[0] = {0, 0, 0};
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a1, b1, c;
            cin >> a1 >> b1 >> c;
            change[i] = {a1, b1, c};
            upd(1, 1, base, b1, b1 + c - 1, i);
        } else {
            int cur;
            cin >> cur;
            int id = zap(1, 1, base, cur);
            if (id == 0) {
                cout << b[cur] << "\n";
            } else {
                cout << a[change[id][0] + cur - change[id][1]] << "\n";
            }
            // cout << zap(1, 0, base - 1, cur) << "\n";
        }
    }
}
