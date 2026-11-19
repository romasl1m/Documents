#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<int> tab(n);
        droptop(0,n){
            cin >> tab[i];
        }
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        vector<int> suf(n);
        suf[n - 1] = tab[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suf[i] = min(suf[i + 1], tab[i]);
        }
        long long base = 0;
        for(int i = 0; i < n - 1; i++){
            base += max(0, tab[i] - suf[i + 1]);
        }
        stack<int> st;
        vector<int> l(n, -1);
        for(int i = 0; i < n; i++){
            while(not st.empty() and tab[st.top()] >= tab[i]){
                st.pop();
            }
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            int nextt = (i + 1 < n) ? suf[i + 1] : 2e9; 
            if(tab[i] < nextt){
                res = max(res, i - l[i] - 1);
            }
        }
        cout << base + res << "\n";
    }
    return 0;
}

