/*
Now playing:
HXG - Uzi Work [Snot or Not]
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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        bool one = false, zero = false;
        droptop(i, 0, n)
        {
            cin >> a[i];
            if (a[i])
                one = true;
        }
        bool ok = true;
        droptop(i, 0, n)
        {
            cin >> b[i];
            if (a[i] != b[i])
                ok = false;
            if (not b[i])
                zero = true;
        }
        if (ok) {
            cout << "0\n";
            continue;
        }
        if (not zero or not one) {
            cout << "-1\n";
            continue;
        }
        int sum = 0, cur = 0;
        droptop(i, 0, n)
        {
            if (a[i] == b[i])
                continue;
            sum += a[i], cur++;
        }
        if (sum % 2 == 0) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
    }
}
