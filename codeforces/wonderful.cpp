#include <iostream>
#include <mutex>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> wec(n);
        vector<bool> tab(100 * (n + 1));
        int cst = n * 100;
        droptop(0,n){
            int x;
            cin >> x;
            wec[i] = 100 / x;
        }
        queue<int> q;
        q.push(0);
        while(not q.empty()){
            int cur = q.front();
            q.pop();
            droptop(0,n){
                if(cur + wec[i] > cst){
                    continue;
                }
                if(tab[cur + wec[i]]) continue;
                q.push(cur + wec[i]);
                tab[cur + wec[i]] = true;
            } 
        }
        bool ok = true;
        droptop(1, n * 100){
            if(not tab[i]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "yes\n";
        else cout << "no\n";
    }
}
