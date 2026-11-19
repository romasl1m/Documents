#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(unsigned long long i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
unordered_map<unsigned long long, unsigned long long> mapa;
unsigned long long a,b,d;
unsigned long long f(unsigned long long w, unsigned long long s){
    return (a * w + b * s) % 1001;
}
unsigned long long dfs(unsigned long long n){
    if(mapa.count(n)) return mapa[n];
    if(n == 1) return mapa[1] = 0;
    unsigned long long best = ULONG_LONG_MAX;
    unsigned long long l = (n > d ? (n - d + 1) >> 1 : 1);
    unsigned long long r = (n + d) >> 1;
    droptop(l, r + 1){
        unsigned long long j = n - i;
        if(i == 0 or j == 0) continue;
        if((i > j ? i - j : j - i) > d) continue;
        best = min(best, dfs(i) + dfs(j) + f(i, j));
    }
    return mapa[n] = best;
}
int main(){
    unsigned long long n;
    cin >> n >> d >> a >> b;
    dfs(n);
    cout << mapa[n];
}
