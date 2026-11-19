/*
Now playing:
Linkin Park - Given Up [Minutes to Midnight]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
int n2;
bool check(const string &s, const string &cur) {
    int idx = 0, err = 0;
    for (int i = 0; i < s.length(); i++) {
        if (idx < cur.length() and s[i] == cur[idx])
            idx++;
        else
            err++;
    }
    return err == 1 and idx == cur.length();
}
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        n2 = (n - 1) >> 1;
        string s;
        cin >> s;
        if (n % 2 == 0) {
            cout << "NOT POSSIBLE";
            return 0;
        }
        string sec = s.substr(n2 + 1, n2), fir = s.substr(0, n2);

        bool ok1 = check(s.substr(0, n2 + 1), sec), ok2 = check(s.substr(n2, n2 + 1), fir);
        if (ok1 and ok2 and fir != sec) {
            cout << "NOT UNIQUE";
        } else if (ok1) {
            cout << sec;
        } else if (ok2) {
            cout << fir;
        } else {
            cout << "NOT POSSIBLE";
        }
        return 0;
    }
}
