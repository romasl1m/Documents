#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define ll long long

int main() {
    raindrop; // Aktywacja szybkiego wejścia/wyjścia
    srand(time(NULL));

    // Zapewniamy, że n i k są przynajmniej równe 1
    int n = (rand() % 999) + 1;
    int k = (rand() % 999) + 1;

    cout << n << " " << k << "\n";

    while (k--) {
        // 'a' musi być mniejsze niż 'n', aby (n - a) było dodatnie i większe od zera
        int a = rand() % n;
        int range = n - a;

        // Zapewniamy, że 'l' wynosi co najmniej 1, aby uniknąć dzielenia przez zero
        int l = (rand() % range) + 1;

        // Bezpieczne dzielenie
        int d = (rand() % range) / l;

        cout << a << " " << l << " " << d << "\n";
    }

    return 0;
}
