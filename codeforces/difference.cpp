/*
Now playing:
Juice WRLD - Something To Prove [Something To Prove]
*/
#include <iostream>
#include <map>
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
#define ll long long

#define i1 __int128

void f(i1 sum) {
    if (sum < 0) {
        cout << '-';
        sum = -sum;
    }
    if (sum > 9) {
        f(sum / 10);
    }
    cout << (int)(sum % 10);
}
ll tab[200'001];
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n)
        {
            cin >> tab[i];
        }
        map<ll, ll> mapa;
        i1 sum = 0, pref = 0;
        droptop(0, n)
        {
            ll cur = tab[i];
            i1 num = pref;
            num -= cur * (i1)i;

            if (mapa.count(cur - 1)) {
                num -= mapa[cur - 1] * (i1)(cur - 1);
                num += mapa[cur - 1] * (i1)cur;
            }

            if (mapa.count(cur + 1)) {
                num -= mapa[cur + 1] * (i1)(cur + 1);
                num += mapa[cur + 1] * (i1)cur;
            }

            sum += num;
            pref += (i1)cur;
            mapa[cur]++;
        }
        f(-sum);
    }
}
