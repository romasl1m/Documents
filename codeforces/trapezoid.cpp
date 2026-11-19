/*
Now playing:
Juice WRLD - Ring Ring (with Rvssian feat. Clever) [Death Race For Love (Bonus Track Version)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct s {
    int a, b, c, d;
};
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> wec(n << 1);
        vector<s> tab(n);
        droptop(0, n)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            tab[i] = {a, b, c, d};
            wec[i] = {a, i};
            wec[i << 1] = {c, i};
        }
        hotbox(wec);
    }
}
