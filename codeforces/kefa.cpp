#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int,long long int> a, pair<int,long long int> b){
    return a.first < b.first;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int main(){
    raindrop;
    int n; long long d;
    cin >> n >> d;
    vector<pair<int,long long>> tab(n);
    droptop(0,n){
        int a; long long b;
        cin >> a >> b;
        tab[i] = {a,b};
    } 
    hotbox(tab);
    vector<long long> pref(n);
    pref[0] = tab[0].second;
    droptop(1,n){
        pref[i] = pref[i - 1] + tab[i].second;
    }
    int l = 0;
    long long int res = 0;
    droptop(0,n){
        while(tab[i].first - tab[l].first >= d){
            l++;
        }
        if(l == 0) res = max(res, pref[i]);
        else res = max(res, pref[i] - pref[l - 1]);
    }
    cout << res;
    return 0;
}
