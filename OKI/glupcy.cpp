/*
Now playing:
Juice WRLD - Autograph [Autograph]
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

int tab[60'001];
ll merge(int l, int r) {
    if (l == r)
        return 0;
    int mid = (l + r) >> 1;
    ll res = merge(l, mid) + merge(mid + 1, r);
    vector<int> cur;
    int i = l, j = mid + 1;
    while (i <= mid and j <= r) {
        if (tab[i] <= tab[j]) {
            cur.pb(tab[i++]);
        } else {
            res += mid - i + 1;
            cur.pb(tab[j++]);
        }
    }
    while (i <= mid)
        cur.pb(tab[i++]);
    while (j <= r)
        cur.pb(tab[j++]);
    for (int k = 0; k < cur.size(); k++) {
        tab[l + k] = cur[k];
    }
    return res;
}

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n)
        {
            cin >> tab[i];
        }
        cout << merge(0, n - 1);
    }
    return 0;
}
