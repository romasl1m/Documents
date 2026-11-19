/*
Now playing:
Huncho Jack - Dubai Shit [Huncho Jack, Jack Huncho]
*/
#include <iostream>
#include <algorithm>
#include <array>
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
pair<int, int> tab[150'001];

constexpr int maks = 45000;
struct prime {
    // std::array<bool, maks> pr;
    // vector<bool> pr;
    // vector<bool> wiz(maks + 1, true);
    array<bool, maks + 1> pr;
    constexpr prime() : pr() {
        droptop(2, maks + 1)
        {
            pr[i] = true;
        }
        for (int i = 2; i * i <= maks; i++) {
            if (pr[i]) {
                for (int j = i * i; j <= maks; j += i) {
                    pr[j] = false;
                }
            }
        }
    }
};
constexpr prime primes;
int main() {
    raindrop;
    int t = 1;
    cookie(t)
    {
        int n;
        cin >> n;
        droptop(0, n)
        {
            cin >> tab[i].first >> tab[i].second;
        }
    }
}
