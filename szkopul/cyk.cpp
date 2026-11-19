/*
Now playing:
Lil Peep - I've Been Waiting (w/ ILoveMakonnen and Fall Out Boy) [I've Been Waiting (w/ ILoveMakonnen and Fall Out Boy)]
*/
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include "cyklib.hpp"
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long

void f() {
    ll start = circular_shift(1), cur = 1, last = start, sum = 1;

    while (true) {
        last = circular_shift(cur), sum += sum;
        if (last <= start)
            break;
        cur <<= 1;
    }

    // if (last == start) {
    //     ll l = (cur >> 1) + 1, r = cur, res = cur;
    //
    //     while (l <= r) {
    //         const ll &mid = l + ((r - l) >> 1);
    //         if (circular_shift(mid) == start)
    //             res = mid, r = mid - 1;
    //         else
    //             l = mid + 1;
    //     }
    //
    //     give_answer(res);
    // }

    ll l = sum - cur + 1, r = sum, res = sum, maks = sum;

    while (l <= r) {
        const int &mid = l + ((r - l) >> 1);
        ll dif = mid - sum;

        if (dif < 0)
            dif = (dif % maks + maks) % maks;
        if (dif == 0) {
            if (last <= start)
                res = mid, r = mid - 1;
            else
                l = mid - 1;
        }

        last = circular_shift(dif), sum += dif;

        if (last <= start)
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    give_answer(res);
}

int main() {
    raindrop;
    int t = 1;
    cin >> t;
    while (t--) {
        try {
            f();
        } catch (const exception &e) {
            cerr << "error " << t << ": " << e.what() << "\n";
            continue;
        } catch (...) {
            cerr << "other error " << t << "\n";
            continue;
        }
    }
    return 0;
}
