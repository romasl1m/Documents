// Drzewa przedzialowe||Segment Trees
// Klasy||Classes
#include <iostream>
#include <vector>
using namespace std;
const int maks = 1 << 17;
int tab[2 * maks];
int lazy[2 * maks];
class graf {
  public:
    vector<int> wec[100001];
    bool wiz[100001];
    int size;
    int n, m;
    graf(int n = 0) {
        this->n = n;
    }
    virtual ~graf() {}
    virtual void fill(int m) {
        this->m = m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            wec[a].push_back(b);
            wec[b].push_back(a);
        }
    }
    virtual int dfs(int w) {
        wiz[w] = true;
        for (int ss : wec[w]) {
            if (not wiz[ss]) {
                dfs(ss);
            }
        }
    }
};
class directed : public graf {
  public:
    directed(int n = 0) : graf(n) {}
    void fill(int m) override {
        this->m = m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            wec[a].push_back(b);
        }
    }
};
void add_punkt_przedzial(int x, int w) {
    w += maks;
    tab[w] += x;
    w /= 2;
    while (w > 0) {
        tab[w] = tab[w / 2] + tab[w / 2 + 1];
        w /= 2;
    }
}
int punkt_przedzial(int a, int b) {
    // counts the sum of elements in the range [a, b]
    int sum = 0;
    a += maks - 1;
    b += maks - 1;
    while (a <= b) {
        if (a % 2 == 1)
            sum += tab[a++];
        if (b % 2 == 0)
            sum += tab[b--];
        a >> 1;
        b >> 1;
    }
    return sum;
}
void add_przedzial_punkt(int a, int b, int x) {
    // adds a value to a range
    a += maks - 1;
    b += maks - 1;
    while (a / 2 != b / 2) {
        if (a % 2 == 0) {
            tab[a + 1] += x;
        }
        if (b % 2 == 1) {
            tab[b - 1] += x;
        }
        a /= 2;
        b /= 2;
    }
}
int przedzial_punkt(int w) {
    // returns the value of every element
    int res = 0;
    w += maks;
    while (w > 0) {
        res += tab[w];
        w /= 2;
    }
    return res;
}
void push_przedzial_przedzial(int w, int l, int r) {
    if (lazy[w] == 0)
        return;
    int sr = (l + r) / 2;
    tab[2 * w] += lazy[w] * (sr - l + 1);
    tab[2 * w + 1] += lazy[w] * (r - sr);
    lazy[2 * w] += lazy[w];
    lazy[2 * w + 1] += lazy[w];
    lazy[w] = 0;
}
void update_przedzial_przedzial(int w, int l, int r, int a, int b, int x) {
    // adds x to every element in da range [a,b]
    if (l > b or r < a)
        return;
    if (a <= l and r <= b) {
        tab[w] += x * (r - l + 1);
        lazy[w] += x;
        return;
    }
    push_przedzial_przedzial(w, l, r);
    int sr = (l + r) / 2;
    update_przedzial_przedzial(2 * w, l, sr, a, b, x);
    update_przedzial_przedzial(2 * w + 1, sr + 1, r, a, b, x);
    tab[w] = tab[w * 2] + tab[2 * w + 1];
}
int query_przedzial_przedzial(int w, int l, int r, int a, int b) {
    // returns the max in da range [a,b]
    if (l > b or r < a)
        return 0;
    if (a <= l and r <= b) {
        return tab[w];
    } // tu mmoze byc zle warunek
    int sr = (l + r) / 2;
    push_przedzial_przedzial(w, l, r);
    int lew = query_przedzial_przedzial(2 * w, l, sr, a, b);
    int praw = query_przedzial_przedzial(2 * w + 1, sr + 1, r, a, b);
    return max(lew, praw);
}
