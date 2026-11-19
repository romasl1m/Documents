/*
Now playing:
Linkin Park - Let You Fade [From Zero (Deluxe Edition)]
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

// bool tab[200'001];
string tab;
int pref[200'001];

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        // droptop(i, 0, n)
        // {
        //     cin >> tab[i];
        // }
        cin >> tab;
        droptop(i, 0, n - 1)
        {
            pref[i + 1] = pref[i] + (tab[i] == tab[i + 1] ? 1 : 0);
        }

        while (q--) {
            int l, r, cur;
            cin >> l >> r >> cur;
            if (l == r) {
                cout << "YES\n";
                continue;
            }
            cout << (((pref[r - 1] - pref[l - 1] + 1) >> 1) > cur ? "NO\n" : "YES\n");
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
