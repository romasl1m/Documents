/*
Now playing:
Lil Skies - Cloudy Skies [Life of a Dark Rose]
*/
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
#define int ll

struct s {
    int a, b, id;
};
bool comp(s a, s b) {
    return a.b > b.b;
}
bool res[500'001];
signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<s> tab(n);
        droptop(i, 0, n)
        {
            cin >> tab[i].a;
            tab[i].id = i;
        }
        droptop(i, 0, n)
        {
            cin >> tab[i].b;
        }
        hotbox(tab);
        int suma = 0, sumb = 0, mina = 0, minb = 0;
        droptop(i, 0, n)
        {
            if (suma <= sumb) {
                suma += tab[i].b;
                res[tab[i].id] = false;
            } else {
                sumb += tab[i].b;
                res[tab[i].id] = true;
            }
        }

        suma = 0, sumb = 0;
        droptop(i, 0, n)
        {
            if (res[tab[i].id]) {
                sumb += tab[i].a;
            } else {
                suma += tab[i].a;
            }
        }
        bool swp = (suma > sumb);
        droptop(i, 0, n)
        {
            if (swp) {
                cout << res[i] << " ";
            } else {
                cout << !res[i] << " ";
            }
        }
    }
}
