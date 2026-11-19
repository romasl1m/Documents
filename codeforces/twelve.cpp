/*
Now playing:
Juice WRLD - Both Ways [The Pre-Party (Extended)]
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

const ll gang[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        ll n;
        cin >> n;
        ll cur = gang[n % 12];
        if (cur <= n) {
            cout << cur << " " << n - cur << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
