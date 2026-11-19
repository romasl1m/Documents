/*
Now playing:

*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define cookie(c, n, a) for (int c = (n); c >= (a); --c)
#define hotbox(wec) wec.begin(), wec.end()
#define pb push_back
#define ll long long

int sparce[18][100'001];
int tab[100'001];

int nwd(int a, int b) {
    if (a < b)
        swap(a, b);
    while (b) {
        int c = a % b;
        a = b, b = c;
    }
    return a;
}

int query(int l, int r) {
    int len = r - l + 1;
    // int k = 31 - __builtin_clz(len);
    int k = __lg(len);
    return nwd(sparce[k][l], sparce[k][r - (1 << k) + 1]);
}

unordered_map<int, ll> cnt;

int f() {
    int n;
    cin >> n;
    droptop(i, 0, n)
    {
        cin >> tab[i], sparce[0][i] = tab[i];
    }

    droptop(j, 1, 18)
    {
        droptop(i, 0, n - (1 << j) + 1)
        {
            sparce[j][i] = nwd(sparce[j - 1][i], sparce[j - 1][i + (1 << (j - 1))]);
        }
    }

    droptop(i, 0, n)
    {
        int l = i;
        while (l < n) {
            int cur = query(i, l), a = l, b = n - 1, res = l;
            while (a <= b) {
                int mid = a + ((b - a) >> 1);
                if (query(i, mid) == cur) {
                    res = mid, a = mid + 1;
                } else {
                    b = mid - 1;
                }
            }
            cnt[cur] += (res - l + 1), l = res + 1;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << cnt[x] << "\n";
    }
    return 0;
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        f();
    }
    return 0;
}
