/*
Now playing:
Travis Scott - WHERE WAS YOU [JACKBOYS 2]
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b) {
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(c, a, n) for (int c = (a); c < (n); ++c)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
#define pb push_back
#define ll long long
int main() {
    raindrop;
    int n = rand() % (10'51);
    cout << n << '\n';
    droptop(i, 0, n)
    {
        cout << rand() % (10'51)
             << " ";
    }
    bool opps = false; // -- no opps left behind
    return 0;
}
