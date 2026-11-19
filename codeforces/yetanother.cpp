/*
Now playing:
Linkin Park - I'LL BE GONE [LIVING THINGS]
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

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        if (k > m) {
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
        droptop(i, 0, n)
        {
            cout << (i % k == 0 ? m - k + 1 : 1) << " ";
        }
        cout << "\n";
    }
}
