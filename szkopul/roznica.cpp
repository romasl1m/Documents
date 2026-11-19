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
#define pb push_back
int cur[27];
vector<int> pos[27];
int main(){
    raindrop;
    int n;
    cin >> n;
    string s;
    cin >> s;
    droptop(0,n){
        pos[s[i] - 'a'].pb(i);
    } 
    int res = 0;
    droptop(0,26){
        if(pos[i].empty()) continue;
        for(int j = 0; j < 26; j++){
            if(i == j or pos[j].empty()) continue;
            int idxi = 0, idxj = 0;
            int sum = 0;
            int min_sum = 0;
            int cmin = 0;
            bool appeared = false;
            while(idxi < pos[i].size() or idxj < pos[j].size()){
                if(idxj == pos[j].size() or (idxi < pos[i].size() and pos[i][idxi] < pos[j][idxj])){
                    sum++;
                    idxi++;
                }else{
                    sum--;
                    idxj++;
                    appeared = true;
                    min_sum = min(min_sum, cmin);
                    cmin = sum;
                }
                if(appeared){
                    res = max(res, sum - min_sum);
                }
            }
        }
    }
    cout << res;
    return 0;
}

