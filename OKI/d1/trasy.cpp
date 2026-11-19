/*
Now playing:

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

vector<int> tree[10'001];
vector<int> wec[10'001];
bitset<10'001> wiz;
int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        droptop(i, 1, n)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
            tree[a].pb(b), tree[b].pb(a);
        }
        int m;
        cin >> m;
        droptop(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            wec[a].pb(b), wec[b].pb(a);
        }
        int q;
        cin >> q;
        while (q--) {
        }
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
