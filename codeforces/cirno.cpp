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
long long res;
long long lln;
void dfs(const string& s, string cur, int w, bool sm, bool bg, int a, int b){
    if(w == s.length()){
        long long ans = stoll(cur);
        res = min(abs(ans -lln),res);
        return;
    }
    if(sm){
        while(w < s.length()){
            cur += char(b + '0');
            w++;
        }
        long long ans = stoll(cur);
        res = min(llabs(ans - lln), res);
        return;
    }
    else if(bg){
        while(w < s.length()){
            cur += char(a + '0');
            w++;
        }
        long long ans = stoll(cur);
        res = min(llabs(ans - lln), res);
        return;
    }
    vector<int> wec = {a,b};
    for(int ss : wec){
        if(ss < s[w] - '0'){
            dfs(s, cur + char(ss + '0'), w + 1, true, false, a, b);
        }else if(ss > s[w] - '0'){
            dfs(s, cur + char(ss + '0'), w + 1, false, true, a, b);
        }else{
            dfs(s, cur + char(ss + '0'), w + 1, false, false, a, b);
        }
    }

}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        string s; int n;
        cin >> lln >> n;
        s = to_string(lln);
        int a,b;
        cin >> a >> b;
        res = (1LL << 62);
        dfs(s, "", 0, false, false, a, b);
        if((int)s.length() > 1){
            int l = s.length() - 1;
            if(b != 0){
                string cur = "";
                cur += char(b + '0');
                droptop(1, l){
                    cur += char(b + '0');
                }
                long long val = stoll(cur);
                res = min(res, llabs(val - lln));
            }
        }
            int l = s.length() + 1;
            int first = (a == 0 ? b : a);
            string cur = "";
            cur += char(first + '0');
            droptop(1, l){
                cur += char(a + '0');
            }
            long long war = stoll(cur);
            res = min(res, llabs(war - lln));

        cout << res << "\n";    
    }
}
