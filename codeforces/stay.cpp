/*
Now playing:
Kavinsky - Odd Look [Kiss Land (Deluxe)]
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
        vector<int> tab(n);
        droptop(0, n)
        {
            cin >> tab[i];
        }
        int res = 0;
        droptop(0, n)
        {
            int l = 0, r = 0;
            for (int j = 0; j < i; j++) {
                if (tab[j] > tab[i])
                    l++;
            }
            for (int j = i + 1; j < n; j++) {
                if (tab[j] > tab[i])
                    r++;
            }
            res += min(l, r);
        }
        cout << res << "\n";
    }
}
