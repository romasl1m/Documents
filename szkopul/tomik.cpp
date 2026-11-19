#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
int counts[1000001];
vector<int> wec[1000001];
int main(){
    raindrop;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int val = (x + 1) % k;        
        counts[val]++;
        wec[val].push_back(i);
    }
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < k; i++){
        if(counts[i] > 0){
            q.push({counts[i], i});
        }
    }
    int pos = 0;
    int res = 0;
    vector<int> order;
    order.reserve(n);
    int left = n;
    while(not q.empty()){
        auto [quan, cur] = q.top();
        q.pop();
        if((pos + cur) % k == k - 1 and not q.empty()){
            auto [quan2, cur2] = q.top();
            q.pop();
            pos = (pos + cur2) % k;
            order.push_back(wec[cur2].back());
            wec[cur2].pop_back();
            if(quan2 > 1) q.push({quan2 - 1, cur2});
            q.push({quan, cur}); 
            left--;
        }else{
            pos = (pos + cur) % k;
            if(pos == k - 1 and left > 1){
                res++;
                pos = 0;
            }
            order.push_back(wec[cur].back());
            wec[cur].pop_back();
            if(quan > 1) q.push({quan - 1, cur});
            left--;
        }
    }
    cout << res << "\n";
    for(int i = 0; i < order.size(); i++){
        cout << order[i] << (i == order.size() - 1 ? "" : " ");
    }
    return 0;
}
