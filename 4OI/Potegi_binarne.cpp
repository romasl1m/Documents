#include <iostream>
using namespace std;
long long pot(long long n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k & 1) {
        long long cur = pot(n, k >> 1);
        return cur * cur * n;
    }
    long long res = pot(n, k >> 1);
    return res * res;
}
bool tab[1000001];
int bin() {
    int l = 0, r = 1000000;
    while (l <= r) {
        int sr = (l + r) >> 1;
        if (tab[sr]) {
            r = sr - 1;
        } else {
            l = sr + 1;
        }
    }
    return r + 1;
}
int main() {
}
