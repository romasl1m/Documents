/*
Now playing:
Future - Ain't Livin Right (feat. Gunna) [Future and Juice WRLD Present... WRLD ON DRUGS]
*/
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include "arc.h"
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define pop pop_back
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define push pb
#define ll long long
#define top back

int main() {
    int t = 1;
    while (t--) {
        int k = inicjuj();
        vector<int> tab;
        tab.reserve(15000000);

        int cur = wczytaj();
        while (cur != 0) {
            tab.pb(cur);
            cur = wczytaj();
        }

        int n = tab.size();
        // vector<int> deb;
        vector<int> s;
        s.reserve(k);
        int left = n - k;
        droptop(i, 0, n)
        {

            while (not s.empty() and s.top() < tab[i] and left > 0) {
                // deb.pop_back(), left--;
                s.pop(), left--;
            }
            if (s.size() < k) {
                // deb.pb(tab[i]);
                s.push(tab[i]);
            } else {
                left--;
            }

            // for (int x : deb) {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        droptop(i, 0, k)
        {
            wypisz(s[i]);
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
