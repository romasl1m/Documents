/*
Now playing:
Sentino - MR. OFFICER [KING SENTO PROLOG]
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
vector<int> wec[303'001];
static int wiz[3001][3001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int s, t, m;
        cin >> s >> t >> m;
        droptop(0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].push_back(b - s);
            // wec[b].push_back(a);
        }
        droptop(1, s + 1)
        {
            for (int j = 0; j < wec[i].size(); j++) {
                for (int k = j + 1; k < wec[i].size(); k++) {
                    int w = wec[i][j], ss = wec[i][k];
                    if (ss < w)
                        swap(ss, w);
                    if (wiz[w][ss]) {
                        cout << ss + s << " " << w + s << " " << i << " " << wiz[w][ss];
                        return 0;
                    } else {
                        wiz[w][ss] = i;
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}
