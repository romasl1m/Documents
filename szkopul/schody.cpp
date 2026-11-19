/*
Now playing:
Linkin Park - Nobody Can Save Me [One More Light]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for(int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

ll tab[1'000'001];
ll need[1'000'001];

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n + 1)
        {
            cin >> tab[i];
        }
        droptop(i, 1, n + 1)
        {
            cin >> need[i];
        }

        int cur = 0;
        ll res = 0;
        deque<pair<ll, ll>> q;
        droptop(i, 1, n + 1)
        {
            cur++;
            if (not q.empty()) {
                res = max(res, q.back().second + cur);
            }

            ll stop = max(0LL, need[i] - tab[i]);
            while (stop and not q.empty()) {
                auto &[beg, end] = q.back();
                ll len = end - beg;
                if (len <= stop) {
                    stop -= len;
                    q.pop_back();
                } else {
                    end -= stop;
                    stop = 0;
                }
            }

            ll nowi = max(0LL, tab[i] - need[i]);
            ll curfree = -cur;
            while (nowi) {
                if (q.empty()) {
                    q.pb({curfree, curfree + nowi});
                    nowi = 0;
                } else {
                    if (curfree < q.front().first) {
                        ll dif = min(nowi, q.front().first - curfree);

                        if (curfree + dif == q.front().first) {
                            q.front().first = curfree;
                        } else {
                            q.push_front({curfree, curfree + dif});
                        }
                        nowi -= dif;
                        curfree = q.front().second;
                    } else {
                        curfree = max(curfree, (ll)q.front().second);
                        ll needed = curfree + nowi;
                        if (q.size() > 1 and needed >= q[1].first) {
                            ll used = q[1].first - curfree;
                            nowi -= max(0LL, used);
                            q[1].first = q.front().first;
                            q.pop_front();
                            curfree = q.front().second;
                        } else {
                            q.front().second = needed;
                            nowi = 0;
                        }
                    }
                }
            }
        }
        if (not q.empty()) {
            res = max(res, q.back().second + cur);
        }
        cout << res << "\n";
    }
}
