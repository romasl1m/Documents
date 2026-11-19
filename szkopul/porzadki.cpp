#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> inv4evr;
vector<int> tree;
vector<int> pos;
vector<int> perm;
int ask(int a, int b) {
    cout << a + 1 << " " << b + 1 << endl;
    int invers;
    cin >> invers;
    return invers;
}
int get(int k, int w = 1) {
    tree[w]--;
    if (w >= n)
        return w - n;
    if (tree[w << 1] < k) {
        return get(k - tree[w << 1], (w << 1) | 1);
    }
    return get(k, w << 1);
}
void upd(int i, int j) {
    if (i == j)
        return;
    ask(i, j);
    swap(pos[perm[j]], pos[perm[i]]);
    swap(perm[i], perm[j]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    inv4evr.resize(n);
    for (int i = 0; i < n; i++) {
        inv4evr[i] = ask(0, i);
    }
    tree.assign(n << 1, 0);
    perm.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        tree[n + i] = 1;
    }
    for (int i = n - 1; i > 0; i--) {
        tree[i] = tree[i << 1] + tree[(i << 1) | 1];
    }
    vector<int> tab(n);
    for (int i = n - 1; i >= 0; i--) {
        tab[i] = get(((inv4evr[i] - inv4evr[0] + i) >> 1) | 1);
    }
    perm[0] = tab[n - 1];
    for (int i = 1; i < n; i++) {
        perm[i] = tab[i - 1];
    }
    for (int i = 0; i < n; i++) {
        pos[perm[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        upd(pos[i], i);
    }
    return 0;
}
