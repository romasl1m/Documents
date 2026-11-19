#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
bool check(int mid, const vector<int>& tab){
   if(mid == 0) return true; 
   vector<int> dziura, space;
   int n = tab.size(), i = 0;
   for(int j = 0; j < mid; j++){
       int cur = 0;
       while(i < n and tab[i] == j){
           cur++;
           i++;
       }
        if(cur == 0){
            dziura.push_back(j);
        }else{
            for(int k = 0; k < cur - 1; k++){
                space.push_back(j);
            }
        }
   }
   while(i < n){
       space.push_back(tab[i]);
       i++;
   }
   if(space.size() < dziura.size()) return false;
   sort(dziura.rbegin(), dziura.rend());
   sort(space.rbegin(), space.rend());
   for(int h = 0; h < dziura.size(); h++){
       if(space[h] < (dziura[h] << 1 | 1)) return false;
   }
   return true;
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> tab(n);
        droptop(0,n){
            int x;
            cin >> x;
            tab[i] = x;
        }
        hotbox(tab);
        int l = 0, r = n;
        int res = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid,tab)){
                res = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout << res << "\n";
    }
}
