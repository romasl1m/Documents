/*
Now playing:
Linkin Park - Forgotten [Hybrid Theory (Bonus Edition)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<pair<int, char>> wec[101], rew[101];
int tab[101];
int dist_arr[101][101];
pair<int, int> par[101][101];
char last[101][101];

void get(pair<int, int> best, char mid, pair<int, int> start) {
    string half = "";
    pair<int, int> cur = best;
    while (cur != start) {
        half += last[cur.first][cur.second];
        cur = par[cur.first][cur.second];
    }

    string half2 = half;
    reverse(half.begin(), half.end());

    string res = half;
    if (mid != '\0')
        res += mid;
    res += half2;
    cout << res << "\n";
}

void bfs(int a, int b, int n) {
    if (a == b) {
        cout << 0 << " \n";
        return;
    }

    droptop(i, 1, n + 1)
    {
        droptop(j, 1, n + 1)
        {
            dist_arr[i][j] = 1e9;
        }
    }

    queue<pair<int, int>> q;
    dist_arr[a][b] = 0;
    q.push({a, b});
    int res = 1e9;

    pair<int, int> best = {-1, -1};
    char mid = '\0';

    while (not q.empty()) {
        auto [w, p] = q.front();
        q.pop();

        int d = dist_arr[w][p];
        if (d >= res)
            continue;

        for (const auto [ss, color] : wec[w]) {
            if (ss == p) {
                if (d + 1 < res) {
                    res = d + 1;
                    best = {w, p};
                    mid = color;
                }
                break;
            }
        }

        for (const auto &[ss, color] : wec[w]) {
            for (const auto &[rewss, rewcolor] : rew[p]) {
                if (rewcolor == color) {
                    if (dist_arr[ss][rewss] == 1e9) {
                        dist_arr[ss][rewss] = d + 2;
                        par[ss][rewss] = {w, p};
                        last[ss][rewss] = color;

                        if (ss == rewss) {
                            if (dist_arr[ss][rewss] < res) {
                                res = dist_arr[ss][rewss];
                                best = {ss, rewss};
                                mid = '\0';
                            }
                        } else {
                            q.push({ss, rewss});
                        }
                    }
                }
            }
        }
    }

    if (res == 1e9) {
        cout << -1 << "\n";
    } else {
        cout << res << " ";
        get(best, mid, {a, b});
    }
}

void f() {
    int n, m;
    cin >> n >> m;
    droptop(i, 0, m)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        wec[a].pb({b, c});
        rew[b].pb({a, c});
    }
    int d;
    cin >> d;
    droptop(i, 0, d)
    {
        cin >> tab[i];
    }

    droptop(i, 0, d - 1)
    {
        bfs(tab[i], tab[i + 1], n);
    }
}

signed main() {
    raindrop;
    int t = 1;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
