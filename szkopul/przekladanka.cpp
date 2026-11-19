/*
Now playing:
Lil Peep - haunt u [LIVE FOREVER]
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

vector<bool> ruch;
int tab[2'001];
int rest[4'000'001];
int res;
int n;
int st;

void add(int cur) {
    if (res > 0 and rest[res - 1] * cur > 0) {
        rest[res - 1] += cur;
    } else {
        rest[res++] = cur;
    }
}
void p() {
    st--;
    if (st < 0) {
        st += n;
    }
    add(1);
}
void p2() {
    st++;
    if (st >= n) {
        st -= n;
    }
    add(n - 1);
}
void m() {
    int nxt[2] = {(st + 1) % n, (st + 2) % n};
    int cur = tab[st];
    tab[st] = tab[nxt[1]];
    tab[nxt[1]] = tab[nxt[0]];
    tab[nxt[0]] = cur;
    add(-1);
}

int main() {
    raindrop;
    int t = 1;
    while (t--) {
        cin >> n;
        int nc = n;
        droptop(i, 0, n)
        {
            cin >> tab[i];
        }
        if (nc <= 2) {
            if (nc == 1 or tab[0] == 1) {
                cout << 0;
                return 0;
            } else {
                cout << 1 << "\n"
                     << "1a";
                return 0;
            }
        }

        droptop(j, 2, nc - 1)
        {
            while (tab[st] != j) {
                p();
            }
            while (tab[(st - 1 + n) % n] != j - 1) {
                p();
                if (tab[(st - 1 + n) % n] != j - 1) {
                    p(), m();
                } else {
                    m(), m();
                }
            }
        }

        while (tab[st] != 1) {
            p();
        }
        if (tab[(st - 1 + n) % n] != nc) {
            if (n % 2 == 1) {
                cout << "NIE DA SIE\n";
                return 0;
            } else {
                p();
                while (tab[(st + 1) % n] != nc) {
                    m(), m(), p2(), p2();
                }
                droptop(i, 0, n - 2)
                {
                    p();
                }
            }
        }

        int rs = 0;
        droptop(i, 0, res)
        {
            if (rest[i] % nc != 0)
                rs++;
        }
        cout << rs << "\n";
        droptop(i, 0, res)
        {
            if (rest[i] % nc != 0) {
                int x = rest[i] % nc;
                if (x > 0)
                    cout << x << 'a' << " ";
                else
                    cout << -x << 'b' << " ";
            }
        }
    }
}
