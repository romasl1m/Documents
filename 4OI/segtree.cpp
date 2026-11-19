/*
Now playing:
Juice WRLD - Hurt Me [Goodbye And Good Riddance]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

const int base = 11;
int lazy[(base << 1) + 5];
int tab[(base << 1) + 5];

int lazy1[(base << 1) + 5];
int tab1[(base << 1) + 5];

void push(int w) {
    if (lazy[w] == 0)
        return;
    tab[w << 1] += lazy[w], tab[w << 1 | 1] += lazy[w];
    lazy[w << 1 | 1] += lazy[w], lazy[w << 1] += lazy[w];
    lazy[w] = 0;
}
void add(int w, int l, int r, int a, int b, int war) {
    if (r < a or l > b)
        return;
    if (a <= l and r <= b) {
        lazy[w] += war;
        tab[w] += war;
        push(w);
        return;
    }
    push(w);
    int mid = (l + r) >> 1;
    add(w << 1, l, mid, a, b, war);
    add(w << 1 | 1, mid + 1, r, a, b, war);
    tab[w] = tab[w << 1] + tab[w << 1 | 1];
}
int sum(int w, int l, int r, int a, int b) {
    if (r < a or l > b)
        return 0;
    if (a <= l or r <= b) {
        return tab[w];
    }
    int mid = (l + r) >> 1;
    return sum(w << 1, l, mid, a, b) + sum(w << 1 | 1, mid + 1, r, a, b);
}

void push_przedzial_przedzial(int w, int l, int r) {
    if (lazy1[w] == 0)
        return;
    int sr = (l + r) / 2;
    tab1[2 * w] += lazy1[w];
    tab1[2 * w + 1] += lazy1[w];
    lazy1[2 * w] += lazy1[w];
    lazy1[2 * w + 1] += lazy1[w];
    lazy1[w] = 0;
}
void update_przedzial_przedzial(int w, int l, int r, int a, int b, int x) {
    // adds x to every element in da range [a,b]
    if (l > b or r < a)
        return;
    if (a <= l and r <= b) {
        tab1[w] += x;
        lazy1[w] += x;
        return;
    }
    push_przedzial_przedzial(w, l, r);
    int sr = (l + r) / 2;
    update_przedzial_przedzial(2 * w, l, sr, a, b, x);
    update_przedzial_przedzial(2 * w + 1, sr + 1, r, a, b, x);
    tab1[w] = tab1[w * 2] + tab1[2 * w + 1];
}
int query_przedzial_przedzial(int w, int l, int r, int a, int b) {
    // returns the max in da range [a,b]
    if (l > b or r < a)
        return 0;
    if (a <= l and r <= b) {
        return tab1[w];
    } // tu mmoze byc zle warunek
    int sr = (l + r) / 2;
    push_przedzial_przedzial(w, l, r);
    int lew = query_przedzial_przedzial(2 * w, l, sr, a, b);
    int praw = query_przedzial_przedzial(2 * w + 1, sr + 1, r, a, b);
    return (lew + praw);
}
int main() {
    srand(time(NULL));
    raindrop;
    int t = 5;
    cookie(t)
    {
        droptop(1, 32)
        {
            cout << tab[base + i] << " ";
            int ent = i;
            if (ent == 1 or ent == 3 or ent == 7 or ent == 15 or ent == 31) {
                cout << endl;
            }
        }
        cout << endl
             << endl;
        droptop(1, 32)
        {
            cout << tab1[base + i] << " ";
            int ent = i;
            if (ent == 1 or ent == 3 or ent == 7 or ent == 15 or ent == 31) {
                cout << endl;
            }
        }
        cout << endl;
        int war = rand() % 10;
        int l = rand() % 10, r = rand() % 10;
        if (l > r)
            swap(l, r);
        cout << "Added " << war << " to " << l << " " << r << endl
             << endl;
        add(1, 0, base - 1, l, r, war);
        update_przedzial_przedzial(1, 0, base - 1, l, r, war);
    }
    droptop(1, 32)
    {
        cout << tab[base + i] << " ";
        int ent = i;
        if (ent == 1 or ent == 3 or ent == 7 or ent == 15 or ent == 31) {
            cout << endl;
        }
    }
    droptop(1, 32)
    {
        cout << tab1[base + i] << " ";
        int ent = i;
        if (ent == 1 or ent == 3 or ent == 7 or ent == 15 or ent == 31) {
            cout << endl;
        }
    }
    // cout << "Sum 1:5 " << sum(1, 0, base - 1, 1, 5);
}
