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
int main(){
    string s;
    cin >> s;
    int res = s[0] - '0';
    priority_queue<int> q;
    q.push(-(s[0] - '0'));
    bool ok = true;
    for(int i = 2; i < s.length(); i += 2){
        if(s[i] < s[i - 2]){
            ok = false;
        }
        q.push(-(s[i] - '0'));
        res += s[i] - '0';
    }
    if(ok) {
        cout << res;
        return 0;
    }else{
        while(q.size() > 1){
            cout << -q.top() << '+';
            q.pop();
        }
    }
    cout << -q.top();
    return 0;
}
