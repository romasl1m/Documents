#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a, n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int tab[1'000'001];
int main() {
    raindrop;
    int n;
    cin >> n;
    droptop(0, n)
    {
        cin >> tab[i];
    }
    int q1;
    cin >> q1;
    cookie(q1)
    {
        int cur;
        cin >> cur;
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        priority_queue<pair<pair<int, int>, int>> q;
        q.push({{0, tab[0]}, 0});
        droptop(1, n)
        {
            auto w = q.top();
            while (i - cur > w.second) {
                q.pop();
                w = q.top();
            }
            dist[i] = -w.first.first + (w.first.second <= tab[i] ? 1 : 0);
            q.push({{-dist[i], tab[i]}, i});
        }
        cout << dist[n - 1] << "\n";
    }
}
