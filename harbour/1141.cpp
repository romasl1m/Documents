/*
Now playing:
Lil Peep - cobain [HELLBOY]
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

const int base = 200'001;
int tree[base << 2];
int tab[base + 1];

void query(int w, int l, int r, const int &cur) {
    if (l == r) {
        tree[w] -= cur;
        cout << l << " ";
        return;
    }

    int mid = l + ((r - l) >> 1);
    if (tree[w << 1] >= cur)
        query(w << 1, l, mid, cur);
    else
        query(w << 1 | 1, mid + 1, r, cur);

    tree[w] = max(tree[w << 1], tree[w << 1 | 1]);
}

void build(int l, int r, int w) {
    if (l == r) {
        tree[w] = tab[l];
        return;
    }
    int mid = l + ((r - l) >> 1);

    build(l, mid, w << 1), build(mid + 1, r, w << 1 | 1);
    tree[w] = max(tree[w << 1], tree[w << 1 | 1]);
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    build(1, n, 1);

    while (m--) {
        int cur;
        cin >> cur;

        if (cur > tree[1]) {
            cout << "0 ";
            continue;
        }
        query(1, 1, n, cur);
    }
}

int main() {
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
