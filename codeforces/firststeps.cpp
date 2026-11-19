/*
Now playing:
Rich The Kid - Plug Walk [The World Is Yours]
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
    while (t--) {
        int n;
        cin >> n;
        int last = 0;
        int cur = 0, res = 0;
        droptop(i, 0, n)
        {
            int x;
            cin >> x;
            if (x >= last) {
                cur++;
            } else {
                res = max(cur, res);
                cur = 1;
            }
            last = x;
        }
        cout << max(cur, res);
    }
}
