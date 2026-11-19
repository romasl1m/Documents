/*
Now playing:
Linkin Park - Forgotten [Hybrid Theory (Bonus Edition)]
*/
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

// vector<pair<int, int>> wec;
// bool wiz[1'000'001];
// void print_tree_edges(vector<int> &deg) {
//     int k = deg.size();
//
//     int res = 0;
//     if (k == 2) {
//         cout << "1\n1 2\n";
//         return;
//     }
//
//     vector<int> leaves;
//     vector<int> mid;
//     // vector<int> deg = tab;
//
//     droptop(i, 0, k)
//     {
//         if (deg[i] == 1) {
//             leaves.pb(i + 1);
//         } else {
//             mid.pb(i + 1);
//         }
//     }
//     while (not mid.empty() and not leaves.empty()) {
//         int w = leaves.back();
//         leaves.pop_back();
//         int ss = mid.back();
//         wiz[w] = wiz[ss] = true;
//         wec.pb({w, ss});
//         // cout << w << " " << ss << "\n";
//
//         deg[ss - 1]--;
//         if (deg[ss - 1] == 1) {
//             mid.pop_back();
//             leaves.pb(ss);
//         }
//     }
//     if (leaves.size() == 2) {
//         wiz[leaves[0]] = wiz[leaves[1]] = true;
//         wec.pb({leaves[0], leaves[1]});
//         // cout << leaves[0] << " " << leaves[1] << "\n";
//     }
//     cout << wec.size() + 1 << "\n";
//     // int cur = 1;
//     // while(not wiz[cur])
//     for (const auto &[a, b] : wec) {
//         cout << a << " " << b << "\n";
//     }
// }

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> jed;
        vector<int> tab(n);
        droptop(i, 0, n)
        {
            cin >> tab[i];
            if (tab[i] == 1)
                jed.pb(i);
        }

        if (jed.size() >= 2) {
            // da sie zm lsc
            cout << "0\n";
        } else if (jed.size() == 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
        cout << "2\n1 2";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
