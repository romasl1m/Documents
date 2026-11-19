/*
Now playing:
Linkin Park - No More Sorrow [Minutes to Midnight]
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
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll tab[1'000'001];
ll cur[1'000'001];
ll pref[1'000'001];
int f(int n, ll k) {
    droptop(i, 1, n + 1)
    {
        cur[i] = tab[i] - k;
        pref[i] = pref[i - 1] + cur[i];
    }
    stack<int> s;
    s.push(0);
    droptop(i, 1, n + 1)
    {
        if (pref[s.top()] >= pref[i]) {
            s.push(i);
        }
    }
    int res = 0;
    for (int i = n; i >= 1; i--) {
        int cur = 0;
        while (not s.empty() and pref[s.top()] <= pref[i]) {
            cur = i - s.top();
            res = max(res, cur);
            s.pop();
        }
    }
    return res;
}

int main() {
    raindrop;
    int t = 1;
    int n;
    cin >> n >> t;
    droptop(i, 1, n + 1)
    {
        cin >> tab[i];
    }
    while (t--) {
        int k;
        cin >> k;
        cout << f(n, k) << " ";
    }
}
