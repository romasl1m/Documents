/*
Now playing:
Linkin Park - Bleed It Out [Minutes to Midnight]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int n;
vector<int> tab;
int f(int m) {
    auto it = upper_bound(tab.begin(), tab.end(), m);
    return it - tab.begin();
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        cin >> n;
        tab.resize(n);
        droptop(i, 0, n)
        {
            cin >> tab[i];
        }
        hotbox(tab);
        int q;
        cin >> q;
        while (q--) {
            int m;
            cin >> m;
            cout << f(m) << "\n";
        }
    }
}
