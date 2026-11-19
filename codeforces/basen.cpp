/*
Now playing:
Metro Boomin - Niagara Falls (Foot or 2) [with Travis Scott and 21 Savage] [HEROES and VILLAINS]
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
#define ll long long
ll tab[100'001];

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n)
        {
            int x;
            cin >> x;
            tab[i] = x;
        }
        ll res = 0;

        stack<int> s;
        droptop(0, n + 1)
        {
            ll cur = (i == n) ? 0 : tab[i];
            while (not s.empty() and tab[s.top()] >= cur) {
                int idx = s.top();
                s.pop();
                ll h = tab[idx];
                ll w = s.empty() ? i : i - s.top() - 1;
                res = max(res, h * w);
            }
            s.push(i);
        }
        cout << res;
    }
}
