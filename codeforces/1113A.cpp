/*
Now playing:
Juice WRLD - Both Ways [The Pre-Party (Extended)]
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
        string s;
        cin >> s;
        vector<bool> wiz(s.length());
        droptop(i, 0, s.length())
        {
            if (s[i] == '0') {
                wiz[i] = true;
                break;
            }
        }
        droptop(i, 0, s.length())
        {
            if (s[i] == '1') {
                wiz[i] = true;
                break;
            }
        }
        droptop(i, 0, s.length())
        {
            if (wiz[i])
                continue;
            cout << s[i];
        }
        cout << "\n";
    }
}
