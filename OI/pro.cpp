#include <iostream>
#include <vector>
using namespace std;
__int16_t prog[10'001];
vector<__int16_t> last, current;
vector<int16_t> tab;
int n,m;
__int16_t count(int i){
    __int16_t res = 0;
    for(int j = 0; j < m; j++){
        if(prog[j] != tab[(i + j) % m]) res++;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> prog[i];
    }
    last.resize(m);
    current.resize(m);
    tab.resize(m);
    for(int i = 0; i < m; i++){
        cin >> tab[i];
    }
    for(int i = 0; i < m; i++){
        last[i] = count(i);
    }
    __int16_t ans = m;
    for(int i = 0; i < m; i++){
        ans = min(ans,last[i]);
    }
    for(int i = 0; i < n - m; i++){
        for(int j = 0; j < m; j++){
            int previous = (j - 1 + m) % m;
            current[j] = last[previous];
            if(tab[previous] != prog[i]) current[j]--;
            if(tab[(j + m - 1) % m] != prog[i + m]) current[j]++;
        }
        for(int i = 0; i < m; i++){
            ans = min(ans, current[i]);
        }
        last = current;
    }
    
    cout << ans;
    return 0;
}
