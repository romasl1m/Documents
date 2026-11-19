/*
Now playing:
HXG - HEADTAP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back

int tab[200'001];
int lef[200'001];
int righ[200'001];
int pos[200'001];
int res = 0;

void f(int l, int r, int a, int b, int sum, const int &n) {
    droptop(l, r + 1)
    {
        int cur = sum - tab[i];
        if (cur >= 1 and cur <= n and a <= pos[cur] and pos[cur] <= b)
            res++;
    }
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
            pos[tab[i]] = i;
        }
        stack<pair<int, int>> s;
        s.push({n + 1, -1});
        lef[0] = -1;
        s.push({tab[0], 0});
        droptop(1, n)
        {
            while (s.top().first < tab[i]) {
                s.pop();
            }
            lef[i] = s.top().second;
            s.push({tab[i], i});
        }

        while (not s.empty())
            s.pop();
        s.push({n + 1, n});
        righ[n - 1] = n;
        s.push({tab[n - 1], n - 1});
        for (int i = n - 2; i >= 0; i--) {
            while (s.top().first < tab[i])
                s.pop();
            righ[i] = s.top().second;
            s.push({tab[i], i});
        }

        droptop(0, n)
        {
            int len = i - lef[i] - 1, len0 = righ[i] - i - 1;
            if (not len or not len0)
                continue;
            if (len < len0) {
                f(lef[i] + 1, i - 1, i + 1, righ[i] - 1, tab[i], n);
            } else {
                f(i + 1, righ[i] - 1, lef[i] + 1, i - 1, tab[i], n);
            }
        }
        cout << res;
    }
    return 0;
}
