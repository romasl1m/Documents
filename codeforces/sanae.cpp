#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pkt{
    int x,y;
};
bool comp(pkt a, pkt b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);

void f(){
    int n;
    cin >> n;
    vector<pkt> tab(n);
    vector<int> ys(n);
    droptop(0,n){
        cin >> tab[i].x >> tab[i].y;
        ys[i] = tab[i].y;
    }
    hotbox(tab);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    vector<int> pmin(n), pmaks(n);
    pmin[0] = pmaks[0] = tab[0].y;
    droptop(1,n){
        pmin[i] = min(pmin[i - 1], tab[i].y);
        pmaks[i] = max(pmaks[i - 1], tab[i].y);
    }

    vector<int> smin(n), smaks(n);
    smin[n - 1] = smaks[n - 1] = tab[n - 1].y;
    for(int i = n - 2; i >= 0; i--){
        smin[i] = min(smin[i + 1], tab[i].y);
        smaks[i] = max(smaks[i + 1], tab[i].y);
    }
    long long res = 0;
    // int lmin = 1, lmaks = 0;
    // droptop(0, n - 1){
    //     if(tab[i].x == tab[i + 1].x) continue;
    //     int low = max(pmin[i], smin[i + 1]);
    //     int high = min(smaks[i + 1], pmaks[i]) - 1;
    //     if(low <= high){
    //         res += (high - low + 1);
    //         int przeciecie = max(low, lmin);
    //         int przecieciem = min(high, lmaks);
    //         if(przeciecie <= przecieciem){
    //             res -= (przecieciem - przeciecie + 1);
    //         }
    //         lmin = low;
    //         lmaks = high;
    //     }else{
    //         lmin = 1;
    //         lmaks = 0;
    //     }
    // }
    droptop(0, n - 1) {
        if(tab[i].x == tab[i + 1].x) continue;
        int low = max(pmin[i], smin[i + 1]);
        int high = min(smaks[i + 1], pmaks[i]) - 1;
        if(low <= high){
            auto it1 = lower_bound(ys.begin(), ys.end(), low);
            auto it2 = upper_bound(ys.begin(), ys.end(), high);
            res += (it2 - it1);
        }
    }
    cout << res << "\n";
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        f();
    }
}
