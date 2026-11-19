#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[5005];
int d[5005];
int res[5005];
bool comp(int a, int b){
    return p[a] > p[b];
}
void f(){
    int n;
    cin >> n;
    vector<int> order(n);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        order[i - 1] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    sort(order.begin(), order.end(), comp);
    vector<int> qorder;
    for(int i = 0; i < n; i++){
        int idx = order[i];
        int r = 0;
        int pos = 0;
        while(pos < qorder.size()){
            if(r == d[idx]){
                break;
            }
            if(qorder[pos] > idx){
                r++;
            }
            pos++;
        }
        if(r < d[idx]){
            cout << -1 << "\n";
            return;
        }
        qorder.insert(qorder.begin() + pos, idx);
    }
    int cur = n;
    for(int i = 0; i < qorder.size(); i++){
        res[qorder[i]] = cur--;
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}
