/*
Now playing:
Juice WRLD - Go Hard 2.0 [Fighting Demons (Deluxe)]
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
        int n, k;
        cin >> n >> k;
        string s, z;
        cin >> s >> z;
        ll num = (1 << k);
        // num -= 2;
        // num /= 3;
        ll axorbs = (k % 2 == 0) ? (num - 1) / 3 : (num + 1) / 3;
        ll as = (num + 1 - axorbs) >> 1, bs = as;
        ll za = 0, zb = 0, zaxb = 0;
        droptop(0, n)
        {
            if (s[i] == '0')
                za++;
            if (z[i] == '0')
                zb++;
            if (s[i] == z[i])
                zaxb++;
        }
        // cout << as * (za * (n - za)) + bs * (zb * (n - zb)) + axorbs * (n - zaxb) << "\n";
        cout << as * (za * (n - za)) + bs * (zb * (n - zb)) + axorbs * (zaxb * (n - zaxb)) << "\n";
    }
}
