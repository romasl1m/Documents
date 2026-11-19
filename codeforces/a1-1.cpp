#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    long long n, m, a, b;
    if (!(std::cin >> n >> m >> a >> b)) return;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(n, m) <= 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
