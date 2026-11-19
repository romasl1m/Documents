/*
Now playing:

*/
#include <iostream>
#include <vector>
#include <cmath>
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
int tab[40'001];
int quan[40'001];

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n * n)
        {
            int x;
            cin >> x;
            quan[x]++;
        }
        int curf = 0;
        vector<pair<int, int>> res;
        int min = 1;
        while (curf < n) {
            while (min <= 40'000 and quan[min] == 0) {
                min++;
            }
            int cur = min;
            if (res.empty()) {
                int b = (int)(sqrt(cur) + 0.5), c = (int)(sqrt(quan[cur] + 0.5));
                tab[b] += c;
                quan[cur] -= c * c;
                curf += c;
            } else {
                int b = res[0].first, c = res[0].second;
                int b2 = cur / b, c2 = quan[cur] / (c << 1);

                tab[b2] += c2;
                for (auto [war, c] : res) {
                    quan[war * b2] -= ((c * c2) << 1);
                }
                quan[b2 * b2] -= c2 * c2;
                curf += c2;
                res.pb({b2, c2});
            }
        }
        droptop(1, 40'001)
        {
            while (tab[i] > 0) {
                tab[i]--;
                cout << i << " ";
            }
        }
    }
}
