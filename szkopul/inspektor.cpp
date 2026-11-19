/*
Now playing:
Juice WRLD - Something To Prove [Something To Prove]
*/
#include <iostream>
#include <algorithm>
#include <cassert>
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

int evt[3][100'001];
int tab[100'001];
int last[100'001];
int ent[100'001];
int esc[100'001];
int in[100'001];

int main() {
    raindrop;
    int t1 = 1;
    cin >> t1;
    cookie(t1)
    {
        int n, m;
        cin >> n >> m;
        droptop(1, m + 1)
        {
            cin >> evt[0][i] >> evt[1][i] >> evt[2][i];
        }
        int l = 1, r = m;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            bool ok = true;
            for (int i = 1; i <= n; i++) {
                tab[i] = m + 1;
                last[i] = 0;
            }
            for (int i = 1; i <= m; i++) {
                in[i] = ent[i] = esc[i] = 0;
            }
            for (int i = 1; i <= mid; i++) {
                int inf = evt[1][i];
                tab[inf] = min(tab[inf], evt[0][i]);
                last[inf] = max(last[inf], evt[0][i]);
            }
            for (int i = 1; i <= n; i++) {
                if (last[i] != 0) {
                    ent[tab[i]]++;
                    esc[last[i]]++;
                }
            }
            for (int i = 1; i <= mid; i++) {
                int czas = evt[0][i];
                if (in[czas] != 0 && in[czas] != evt[2][i] + 1) {
                    ok = false;
                } else {
                    in[czas] = evt[2][i] + 1;
                }
            }
            int sl = n, cur = 0, before = 0, idk = 0;
            for (int i = 1; i <= m; i++) {
                if (in[i] == 0 or not ok)
                    continue;
                for (int j = 0; j < ent[i]; j++) {
                    if (before > 0)
                        before--;
                    else
                        sl--;
                    cur++;
                }
                while (in[i] > cur + before + idk) {
                    before++;
                    sl--;
                }
                if (in[i] < cur) {
                    ok = false;
                } else {
                    while (in[i] < cur + before + idk) {
                        if (idk > 0)
                            idk--;
                        else
                            before--;
                    }
                }
                assert(not ok or in[i] == cur + before + idk);
                assert(cur >= 0);
                assert(before >= 0);
                assert(idk >= 0);
                for (int j = 0; j < esc[i]; j++) {
                    cur--;
                    idk++;
                }
                if (cur < 0)
                    ok = false;
                if (sl < 0)
                    ok = false;
            }
            // bool ok = true;
            // droptop(1, n + 1)
            // {
            //     last[i] = 0;
            //     tab[i] = m + 1;
            // }
            // droptop(1, m + 1)
            // {
            //     in[i] = ent[i] = esc[i] = 0;
            // }
            // droptop(1, mid + 1)
            // {
            //     tab[evt[1][i]] = min(tab[evt[1][i]], evt[0][i]);
            //     last[evt[1][i]] = max(last[evt[1][i]], evt[0][i]);
            // }
            //
            // droptop(1, n + 1)
            // {
            //     if (last[i] == 0)
            //         continue;
            //     ent[tab[i]]++;
            //     esc[last[i]]++;
            // }
            // droptop(1, mid + 1)
            // {
            //     if (in[evt[0][i]] != 0 and in[evt[0][i]] != evt[2][i]) {
            //         ok = false;
            //     } else {
            //         in[evt[0][i]] = evt[2][i] + 1;
            //     }
            // }
            //
            // int sl = n, cur = 0, before = 0, idk = 0;
            // droptop(1, m + 1)
            // {
            //     if (in[i] == 0 or not ok)
            //         continue;
            //     for (int j = 0; j < ent[i]; j++) {
            //         if (before > 0)
            //             before--;
            //         else
            //             sl--;
            //         cur++;
            //     }
            //     while (in[i] > cur + before + idk) {
            //         before++, sl--;
            //     }
            //     if (in[i] < cur) {
            //         ok = false;
            //     } else {
            //         while (in[i] < cur + before + idk) {
            //             if (idk > 0)
            //                 idk--;
            //             else
            //                 before--;
            //         }
            //     }
            //
            //     assert(not ok or in[i] == cur + before + idk), assert(cur >= 0), assert(before >= 0), assert(idk >= 0);
            //
            //     for (int j = 0; j < esc[i]; j++) {
            //         cur--, idk++;
            //     }
            //     if (sl < 0)
            //         ok = false;
            // }
            if (ok)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << "\n";
    }
}
