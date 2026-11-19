#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long tab[200'001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long d_input, n;
    if (!(cin >> d_input >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    sort(tab, tab + n);

    queue<long long> q1, q2;
    for (int i = 0; i < n; i++) {
        q1.push(tab[i]);
    }

    long long total_cost = 0;

    auto get_min = [&]() {
        long long val;
        if (q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
            val = q1.front();
            q1.pop();
        } else {
            val = q2.front();
            q2.pop();
        }
        return val;
    };

    while (q1.size() + q2.size() > 1) {
        long long t1 = get_min();
        long long t2 = get_min();
        long long combined = t1 + t2;
        total_cost += combined;
        q2.push(combined);
    }

    cout << total_cost << " ";

    return 0;
}
