#include <iostream>
using namespace std;
const int base = 2e5;
int maks[(base | 1) << 1];
int pref[(base | 1) << 1];
int suf[(base | 1) << 1];
int sum[(base | 1) << 1];
int cur = 1;

void f(int i, int w){
    int war = base + i;
    sum[war] += w;
    suf[war] = pref[war] = maks[war] = max(0,sum[war]);
    while(war > 1){
        war >>= 1;
        sum[war] = sum[war << 1] + sum[(war << 1) | 1];
        suf[war] = max(suf[(war<<1)|1], sum[(war<<1)|1] + suf[(war<<1)]);
        pref[war] = max(pref[(war<<1)], sum[(war<<1)] + pref[(war<<1)|1]);
        maks[war] = max(maks[war << 1], maks[(war << 1) | 1]);
        maks[war] = max(maks[war], pref[(war << 1) | 1] + suf[(war << 1)]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k,d;
    cin >> n >> m >> k >> d;
    // while(cur <= n - d) (cur <<= 1);
    for(int i = 1; i <= n - d; i++){
        f(i,-k);
    }
    long long kd = (long long)k * (long long)d;
    while(m--){
        int a,b;
        cin >> a >> b;
        f(a,b);
        if(maks[1] <= kd) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
