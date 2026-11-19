/*
Now playing:
Juice WRLD - Starstruck [Starstruck]
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
int tab[25];
vector<pair<int, int>> wec;

int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        wec.resize(n);
        droptop(1, n + 1)
        {
            cin >> tab[i];
            wec[i] = {tab[i], i};
        }

        hotbox(wec);
    }
}
