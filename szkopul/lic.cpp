/*
Now playing:
Lil Peep - U Said [Come Over When You're Sober, Pt. 1]
*/
#include "cliclib.h"
// #include <iostream>
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
int idx[30'001];
int dp[30'001][125];

int main() {
    // raindrop;
    int t = 1;
    cookie(t)
    {
        int n = inicjuj();
        vector<int> wec;
        for (int i = 1; i <= n; (i <<= 1)) {
            for (int j = 1; i * j <= n; j *= 3) {
                wec.pb(i * j);
            }
        }
        hotbox(wec);
        droptop(0, wec.size())
        {
            idx[wec[i]] = i;
        }
        int cur = idx[1];
        for (int j = n - 1; j >= 0; j--) {
            for (int i = wec.size() - 1; i >= 0; i--) {
                int s = wec[i];
                if (j + s >= n) {
                    dp[j][i] = 1;
                    continue;
                }
                bool win = false;
                if (dp[j + s][cur] == 1) {
                    win = true;
                }

                if (not win) {
                    // if (j + (s << 1) == n) {
                    //     win = false;
                    if (j + (s << 1) >= n) {
                        win = true;

                    } else if (dp[j][idx[cur + (s << 1)]] == 1) {
                        win = true;
                    }
                }

                if (not win) {
                    if (j + (s * 3) >= n) {
                        win = true;
                    } else if (dp[j][idx[cur + (s * 3)]] == 1) {
                        win = true;
                    }
                }

                dp[j][i] = win ? 2 : 1;
            }
        }
        int j = 0, s = 1;
        while (true) {
            // if (j + s >= n)
            //     break;
            int move = 1, next = j + s;

            if (next >= n or (next < n and dp[next][cur] == 1)) {
                move = 1;
                j += s;
                s = 1;
            } else if (j + (s << 1) >= n or (j + (s << 1) < n and dp[j][idx[s << 1]] == 1)) {
                s <<= 1;
                move = 2;
            } else {
                s *= 3;
                move = 3;
            }
            alojzy(move);

            // if (j + s >= n)
            //     break;

            move = bajtazar();
            if (move == 1) {
                j += s;
                s = 1;
            } else if (move == 2) {
                s <<= 1;
            } else
                s *= 3;
        }
    }
    return 0;
}
