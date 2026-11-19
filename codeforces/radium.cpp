/*
Now playing:
Juice WRLD - Make Believe [Death Race For Love (Bonus Track Version)]
*/
#include <iostream>
#include <algorithm>
#include <set>
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
    cookie(t)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<int>> tab(n, vector<int>(m));
        vector<set<pair<int, int>>> row(n), col(m);
        droptop(0, n)
        {
            for (int j = 0; j < m; j++) {
                cin >> tab[i][j];
                row[i].insert({tab[i][j], j});
                row[j].insert({tab[i][j], i});
            }
        }
        cookie(q)
        {
            int i, j, z;
            cin >> i >> j >> z;
            i--;
            j--;
            row[i].erase(tab[i][j]);
            col[j].erase(tab[i][j]);
            tab[i][j] = z;
            row[i].insert(tab[i][j]);
            col[i].insert(tab[i][j]);
        }
    }
}
