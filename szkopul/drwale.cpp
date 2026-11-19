/*
Now playing:
Linkin Park - Let You Fade [From Zero (Deluxe Edition)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <bitset>
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
bitset<2'500'001> dp;
int tab[1'000'001];

int f() {
    int n;
    cin >> n;
    int maks = 0, sum = 0;

    droptop(i, 0, n)
    {
        cin >> tab[i];
        sum += tab[i];
        if (tab[maks] < tab[i])
            maks = i;
    }

    int half = (sum - tab[maks]) >> 1;
    vector<int> cnt(half + 1, 0);
    droptop(i, 0, n)
    {
        if (i != maks and tab[i] <= half)
            cnt[tab[i]]++;
    }

    droptop(i, 1, half + 1)
    {
        if (cnt[i] < 3)
            continue;
        int cur = (cnt[i] - 1) >> 1;
        cnt[i] -= (cur << 1);
        if ((i << 1) <= half)
            cnt[i << 1] += cur;
    }

    dp[0] = true;
    droptop(i, 1, half + 1)
    {
        droptop(j, 0, cnt[i])
        {
            dp |= (dp << i);
        }
    }

    for (int i = half; i >= 0; i--) {
        if (dp[i])
            return i + tab[maks];
    }
    return tab[maks];
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            cout << f();
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
