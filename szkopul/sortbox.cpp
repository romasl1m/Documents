/*
Now playing:
Future - Ain't Livin Right (feat. Gunna) [Future Juice WRLD Present... WRLD ON DRUGS]
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

int tab[1001];
bool wiz[1001];
int cycle[1001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        bool ok = true;
        droptop(1, n + 1)
        {
            cin >> tab[i];
            if (tab[i] != i)
                ok = false;
        }
        if (ok) {
            cout << 0 << "\n";
            return 0;
        }
        vector<vector<int>> cycles;
        droptop(1, n + 1)
        {
            if (wiz[i] or tab[i] == i)
                continue;
            vector<int> c;
            int cur = i;
            while (not wiz[cur]) {
                wiz[cur] = true;
                c.pb(cur);
                cur = tab[cur];
            }
            cycles.pb(c);
        }
        if (cycles.size() == 1) {
            cout << 1 << "\n"
                 << cycles[0].size() << ": ";
            droptop(0, cycles[0].size())
            {
                cout << cycles[0][i] << (i == cycles[0].size() - 1 ? "" : " ");
            }
            cout << "\n";
            return 0;
        }
        vector<int> cur;
        droptop(0, cycles.size())
        {
            cur.pb(cycles[i].front());
        }
        cout << "2\n"
             << cur.size() << ": ";
        droptop(0, cur.size())
        {
            cout << cur[i] << (i == cur.size() - 1 ? "" : " ");
        }
        // int x = tab[cur.front()];
        // droptop(0, cur.size() - 1)
        // {
        //     tab[cur[i]] = tab[cur[i + 1]];
        // }
        // tab[cur.back()] = x;
        vector<int> nxt(n + 1);
        droptop(1, n + 1)
        {
            nxt[i] = tab[i];
        }
        droptop(0, cur.size())
        {
            int from = cur[i];
            int to = cur[(i + 1) % cur.size()];
            nxt[to] = tab[from];
        }
        cout << "\n";

        cur.clear();
        droptop(1, n + 1)
        {
            tab[i] = nxt[i];
            wiz[i] = false;
        }
        vector<int> cycle1;
        droptop(1, n + 1)
        {
            if (wiz[i] or tab[i] == i)
                continue;
            int cur1 = i;
            while (not wiz[cur1]) {
                wiz[cur1] = true;
                cycle1.pb(cur1);
                cur1 = tab[cur1];
            }
            break;
        }
        cout << cycle1.size() << ": ";
        droptop(0, cycle1.size())
        {
            cout << cycle1[i] << (i == cycle1.size() - 1 ? "" : " ");
        }
        cout << "\n";
        return 0;
    }
}
