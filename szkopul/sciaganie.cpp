/*
Now playing:
Juice WRLD - Lightyears (with Young Thug) [Lightyears (with Young Thug)]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        droptop(0, n)
        {
            cin >> a[i];
        }
        droptop(0, n)
        {
            cin >> b[i];
        }
        int res = 0;
        droptop(-(n - 1), n)
        {
            int cur = 0;
            int start = max(0, -i), end = min(n - 1, n - 1 - i);
            for (int j = start; j <= end; j++) {
                if (a[j] == b[j + i])
                    continue;
                cur++;
            }
            res = max(res, cur);
            // if (res == cur) {
            //     cout << "new best " << i << endl;
            // }
        }
        cout << res << "\n";
    }
}
