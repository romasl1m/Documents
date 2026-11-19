/*
Now playing:
Future, Juice WRLD - Realer N Realer
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
int main() {
    raindrop;
    int t = 1;
    cin >> t;
    cookie(t)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> tab(n << 1);
        // vector<int> wec(70);
        long long total = 0;
        droptop(0, n << 1)
        {
            cin >> tab[i];
            total ^= tab[i];
        }
        // int start = 0;
        // long long kcp = k;
        // while (kcp > 1) {
        //     kcp >>= 1;
        //     start++;
        // }
        // bool ok = false;
        // droptop(start, 70)
        // {
        //     if (wec[i] & 1) {
        //         cout << 1 << "\n";
        //         droptop(1, (n << 1) | 1)
        //         {
        //             cout << "1 ";
        //         }
        //         cout << "\n";
        //         ok = true;
        //         break;
        //     }
        // }
        // if (ok)
        //     continue;
        if (total >= k) {
            cout << 1 << "\n";
            droptop(0, n << 1)
            {
                cout << "1 ";
            }
            cout << "\n";
            continue;
        }
        int maks = 0;
        droptop(0, n << 1)
        {
            if ((total ^ tab[i]) >= k) {
                maks = i;
            }
        }
        cout << "2\n";
        droptop(0, maks)
        {
            cout << "1 ";
        }
        cout << "2 ";
        droptop(maks + 1, n << 1)
        {
            cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}
