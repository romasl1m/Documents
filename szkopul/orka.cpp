/*
Now playing:
Kavinsky - Nightcall [Nightcall]
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

int tab[2'001][2'001];
int sumn[2'001][2'001];
int summ[2'001][2'001];
int k, n, m;

int f(int l, int &used) {
    used = 0;
    int px = 1, kx = n, py = 1, ky = m, res = 0;
    while (px <= kx and py <= ky) {
        res++;
        if (sumn[kx][py] - sumn[px - 1][py] <= k)
            py++;
        else if (sumn[kx][ky] - sumn[px - 1][ky] <= k)
            ky--;
        else if (l > 0 and summ[px][ky] - summ[px][py - 1] <= k) {
            px++;
            l--;
            used++;
        } else if (summ[kx][ky] - summ[kx][py - 1] > k)
            return 1e9;
        else
            kx--;
    }
    return res;
}
int check() {
    droptop(x, 1, n + 1)
    {
        droptop(y, 1, m + 1)
        {
            sumn[x][y] = sumn[x - 1][y] + tab[x][y];
            summ[x][y] = summ[x][y - 1] + tab[x][y];
        }
    }
    int res = 1e9;
    for (int x = n; x >= 0; x--) {
        int ss;
        res = min(res, f(x, ss));
        x = min(x, ss);
    }
    return res;
}
void rot() {
    droptop(x, 1, n + 1)
    {
        droptop(y, 1, m + 1)
        {
            summ[x][y] = tab[x][y];
        }
    }
    droptop(x, 0, n + 1)
    {
        droptop(y, 0, m + 1)
        {
            tab[y][x] = summ[x][y];
        }
    }
    swap(n, m);
}
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        cin >> k >> m >> n;
        droptop(i, 1, n + 1)
        {
            droptop(j, 1, m + 1)
            {
                cin >> tab[i][j];
            }
        }
        int res = check();
        rot();
        cout << min(res, check());
    }
}
