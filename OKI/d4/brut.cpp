/*
Now playing:
Trippie Redd - How Much X (feat. Tory Lanez) [NDA]
*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int tab[1'001];
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        while (k--) {
            int a, l, d;
            cin >> a >> l >> d;
            droptop(i, 0, l)
            {
                tab[a]++;
                a += d;
            }
        }

        droptop(i, 1, n + 1)
        {
            cout << tab[i] << " ";
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
