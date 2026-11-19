#include<iostream>

using namespace std;

int t, n, m;

pair <int, int> solve() {
    if(n > 2 && m > 2) {
        int a, b, c, d;
        cout << "? 1 1" << endl;
        cin >> a;
        cout << "? 1 2" << endl;
        cin >> b;
        cout << "? 1 3" << endl;
        cin >> c;
        cout << "? 2 2" << endl;
        cin >> d;
        if(b < a && b < c && b < d) {
            return {1, 2};
        }
    }
    return {1, 1};
}

int main() {
    cin >> t >> n >> m;
    pair <int, int> ans = solve(); 
    cout << "! " << ans.first << ' ' << ans.second << endl;  

    return 0;
}