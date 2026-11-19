#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
const int base = 1 << 20;
long long mint[base << 1];
long long makst[base << 1];

pair<long long, int> maxs(pair<long long, int> a, pair<long long,int> b){
    if(a.first > b.first) return a;
    return b;
}
pair<long long, int> mins(pair<long long, int> a, pair<long long,int> b){
    if(a.first < b.first) return a;
    return b;
}
void upd(int w, long long minw, long long maksw){
    w += base;
    mint[w] = minw; makst[w] = maksw;
    w >>= 1;
    while(w >= 1){
        mint[w] = min(mint[w << 1], mint[(w << 1) | 1]);
        makst[w] = max(makst[w << 1], makst[(w << 1) | 1]);
        w >>= 1;
    }
}
int maksf(int w = 1){
    while(w < base){
        if(makst[w << 1] == makst[w]) w = w << 1;
        else w = (w << 1) | 1;
    }
    return w - base; 
}
int minf(int w = 1){
    while(w < base){
        if(mint[w << 1] == mint[w]) w = w << 1;
        else w = (w << 1) | 1;
    }
    return w - base;
}

int main(){
    raindrop;
    long long n,k;
    cin >> n >> k;
    long long sum = 0;
    droptop(0,n){
        long long x;
        cin >> x;
        mint[base + i] = x;
        makst[base + i] = x;
        sum += x;
    }
    if(sum > n * k){
        cout << "NIE\n";
        return 0;
    }
    droptop(base + n,(base << 1)){
        mint[i] = 1e18;
        makst[i] = -1e18;
    }
    for(int i = base - 1; i >= 1; i--){
        mint[i] = min(mint[i << 1], mint[(i << 1) | 1]);
        makst[i] = max(makst[i << 1], makst[(i << 1) | 1]);
    }
    cout << "TAK\n";
    droptop(0,n){ 
        int id1 = minf();
        long long war1 = mint[base + id1];
        upd(id1,1e18,-1e18);
        long long cur1 = war1;
        long long cur2 = 0;
        int id2 = -1;
        if(cur1 < k and i < n - 1){
            id2 = maksf();
            long long war2 = makst[base + id2];
            if(war2 >= 0){
                cur2 = min(k - cur1, war2);
                if(cur2 > 0){
                    upd(id2, war2 - cur2, war2 - cur2);
                }else{
                    id2 = -1;
                }
            }else{
                id2 = -1;
            }
        }
        if(id2 == -1){
            if(cur1 == 0){
                cout << "0\n";
                continue;
            }
            cout << "1 " << id1 + 1 << " " << cur1 << "\n";
        }else{
            if(cur1 == 0 and cur2 > 0){
                cout << "1 " << id2 + 1 << " " << cur2 << "\n";
                continue;
            }
            else if(cur1 > 0 and cur2 == 0){
                cout << "1 " << id1 + 1 << " " << cur1 << "\n";
                continue;
            }
            if(cur1 == 0 and cur2 == 0){
                cout << "0\n";
            }
            cout << "2 " << id1 + 1 << " " << cur1 << " " << id2 + 1 << " " << cur2 << "\n";
        }
    }
}
