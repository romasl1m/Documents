/*
Now playing:
Lil Peep - Better Off (Dying) [Come Over When You're Sober, Pt. 1]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a > b;
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
        hotbox(tab);
        bool ok = true;
        droptop(2, n)
        {
            if (tab[i] == tab[i - 2] % tab[i - 1])
                continue;
            ok = false;
            break;
        }
        if (not ok) {
            cout << -1 << "\n";
            continue;
        }
        cout << tab[0] << " " << tab[1] << "\n";
    }
}
