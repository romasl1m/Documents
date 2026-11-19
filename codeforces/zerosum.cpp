/*
Now playing:
Lil Peep - s*x [last nite] [s*x [last nite]]
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
        vector<int> tab(n);
        int sum = 0;
        droptop(i, 0, n)
        {
            cin >> tab[i];
            sum += tab[i];
        }
        cout << ((abs(sum) % 4 == 0) ? "YES\n" : "NO\n");
    }
}
