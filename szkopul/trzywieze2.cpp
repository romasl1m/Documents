/*
Now playing:
Travis Scott - STARGAZING [ASTROWORLD]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
int tab[3][1'000'001];

int f(char c) {
    if (c == 'S')
        return 0;
    if (c == 'B')
        return 1;
    return 2;
}

bool ok(int a, int b) {
    int cur[3];
    droptop(0, 3)
    {
        cur[i] = tab[i][b] - tab[i][a - 1];
    }
    if (cur[0] and (cur[0] == cur[1] or cur[0] == cur[2])) {
        return false;
    }
    if (cur[1] and cur[1] == cur[2]) {
        return false;
    }
    return true;
}

int res = 0;
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> set;
        droptop(0, 3)
        {
            set.insert(s[i]);
        }
        if (set.size() == 1 or set.size() == 3) {
        } else {
            res = 3;
        }
        set.clear();

        for (char c : s) {
            set.insert(c);
        }
        if (set.size() == 1) {
            cout << "NIE";
            return 0;
        }
        bool dif = false;
        droptop(0, n)
        {
            if (s[i] != s[i % 3]) {
                dif = true;
                break;
            }
        }
        if (not dif) {
            if (res == 0) {
                cout << "NIE";
                return 0;
            }
            cout << res;
            return 0;
        }
        droptop(1, n + 1)
        {
            tab[f(s[i - 1])][i]++;
            for (int j = 0; j < 3; j++) {
                tab[j][i] += tab[j][i - 1];
            }
        }
        droptop(1, 4)
        {
            for (int j = i; j <= n; j++) {
                if (ok(i, j))
                    res = max(res, j - i + 1);
            }
        }
        for (int j = n - 2; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                if (ok(i, j))
                    res = max(res, j - i + 1);
            }
        }
        cout << res;
    }
    return 0;
}
