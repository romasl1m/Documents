#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,m,l;
        cin >> n >> m >> l;
        vector<int> wec(n + 2);
        for(int i = 1; i <= n; i++){
            cin >> wec[i];
        }
        wec[0] = 0;
        wec[n + 1] = l;
        multiset<int> q;
        for(int i = 1; i <= m; i++){
            q.insert(0);
        }
        vector<int> divtb(n + 2);
        divtb[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            divtb[i] = min(divtb[i + 1] + 1, m);
        }

        queue<int> toadd;
        for(int i = 0; i < n; i++){
            int add = wec[i + 1] - wec[i];
            
            if(wec[i] == wec[i + 1]) continue;
            while(!q.empty() and *q.rbegin() > 0){
                auto it = prev(q.end());
                add += *it;
                q.erase(it);
                q.insert(0);
            }
            int divider = divtb[i];
            int mod = add % divider;
            // cout << mod << " " << add << endl;
            add /= divider;
            for(int j = 0; j < mod and q.size() >= 1; j++){
                int cur = *q.begin();
                q.erase(q.begin());
                cur += add + 1;
                // cout << "CUR " << cur << endl;
                q.insert(cur);
            }
            // cout << add << endl;
            for(int j = mod; j < divider and q.size() >= 1; j++){
                int cur = *q.begin();
                q.erase(q.begin());
                // cout << cur << " ";
                cur += add;
                // cout << "CUR " << cur << endl;
                // cout << "CUR1 " << cur << endl;
                // toadd.push(cur);
                q.insert(cur);
            }
            // while(not toadd.empty()){
            //     // cout << "TADD" << toadd.front() << " ";
            //     q.insert(toadd.front());
            //     toadd.pop();
            // }
            if(not q.empty()){
                cout << *prev(q.end()) << " ";
                q.erase(prev(q.end()));
                q.insert(0);
                cout << "Qtop AFTER "<< *q.rbegin() << endl;
            }
            // cout << "after changes num " << i << " " << " q.size() is " << q.size() << endl;
        }
        cout << *q.rbegin() + l - wec[n] << "\n";
    }
}
