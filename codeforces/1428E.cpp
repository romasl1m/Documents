/*
Now playing:
Artemas - Sink or Swim [Sink or Swim]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll prior(ll cur, ll part) {
    ll cal = cur / part,
       mod = cur - cal * part;

    return (cal * cal) * (part - mod) + ((cal + 1) * (1 + cal) * mod);
}

void f() {
    int n, k;
    cin >> n >> k;
    priority_queue<pair<ll, pair<ll, ll>>> q;
    ll res = 0;
    droptop(i, 0, n)
    {
        ll x;
        cin >> x;
        res += (x * x);
        q.push({prior(x, 1) - prior(x, 2), {x, 2}});
    }

    droptop(i, 0, k - n)
    {
        auto cur = q.top();
        q.pop();

        res -= cur.first;
        int a = cur.second.first, b = cur.second.second;

        q.push({prior(a, b) - (prior(a, b + 1)), {a, b + 1}});
    }

    // while (not q.empty()) {
    //     ll cur = (ll)q.top();
    //     q.pop();
    //
    //     res += cur * cur;
    // }

    cout << res;
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
