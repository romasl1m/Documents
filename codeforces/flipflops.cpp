#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n,c,k;
        cin >> n >> c >> k;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            q.push(x);
        }
        while(not q.empty()){
            long long cur = q.top();
            if(cur > c){
                break;
            }
            long long add = 0;
            if(k > 0){
                add = min(k,c - cur);
                k -= add;
            }
            c += add + cur; 
            q.pop();
        }
        cout << c << "\n";
    }
}
