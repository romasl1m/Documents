/*
Now playing:
Future - Ain't Livin Right (feat. Gunna) [Future and Juice WRLD Present... WRLD ON DRUGS]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); c++)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "TEST " << t << endl
        //      << endl;
        int n, q;
        cin >> n >> q;
        // vector<int> a(n + 1), b(n + 1);
        string a, b;
        cin >> a >> b;
        // droptop(i, 1, n + 1)
        // {
        //     cin >> a[i];
        // }
        // droptop(i, 1, n + 1)
        // {
        //     cin >> b[i];
        // }

        vector<int> bros(n + 1), ops(n + 1), gng(n + 1); // ops 01 gng 10
        droptop(i, 0, n)
        {
            bros[i + 1] = bros[i] + (a[i] == b[i] ? 1 : 0),
                     ops[i + 1] = ops[i] + ((a[i] == '0' and b[i] == '1') ? 1 : 0),
                     gng[i + 1] = gng[i] + ((a[i] == '1' and b[i] == '0') ? 1 : 0);
        }

        while (q--) {
            // cout << "QUERY " << endl
            //      << endl;
            int l, r;
            cin >> l >> r;
            // l++, r++;
            int bro = bros[r] - bros[l - 1],
                op = ops[r] - ops[l - 1],
                gang = gng[r] - gng[l - 1];
            // cout << bro << " " << op << " " << gang << endl;
            if (bro >= abs(op - gang)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}
