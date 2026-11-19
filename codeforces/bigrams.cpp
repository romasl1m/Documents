/*
Now playing:
Lil Peep - haunt u [LIVE FOREVER]
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
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        cin >> n;
        int res = 0;
        droptop(0, n)
        {
            int x;
            cin >> x;
            if (x >= 2) {
                res += (x >> 1) + (x % 2);
            }
        }
        cout << (res >= 2 ? "YES\n" : "NO\n");
    }
}
