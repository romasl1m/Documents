/*
Now playing:
Otsochodzi - CHCĘ CIĘ CAŁOWAĆ I SŁUCHAĆ KING KRULE [RIOTT]
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
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

bool checkf(int mid, const vector<int> &tab) {
    int sum = tab[mid];
    droptop(i, 0, mid)
    {
        sum += tab[i];
    }
    droptop(i, mid + 1, tab.size())
    {
        if (tab[i] > sum)
            return false;
        sum += tab[i];
    }
    return true;
}

int f() {
    int n;
    cin >> n;
    vector<int> tab(n), orig(n);
    droptop(i, 0, n)
    {
        cin >> tab[i];
        orig[i] = tab[i];
    }
    hotbox(tab);

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (checkf(mid, tab))
            r = mid;
        else
            l = mid + 1;
    }

    cout << n - l << "\n";
    droptop(i, 0, n)
    {
        if (orig[i] >= tab[l])
            cout << i + 1 << " ";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        f();
        cout << "\n";
    }
    return 0;
}
