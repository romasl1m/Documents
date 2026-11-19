#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}
bool comp1(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
int tab[100'001];
bool res[1'000'001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> wec(n, vector<int> (3));
    for(int i = 0; i < n; i++){
        cin >> wec[i][0] >> wec[i][1] >> wec[i][2];
    }
    sort(wec.begin(), wec.end(), comp); 
    int p;
    cin >> p;
    vector<vector<int>> que(p, vector<int> (4));
    for(int i = 0; i < p; i++){
        int a,b,c;
        cin >> a >> b >> c;
        que[i] = {a,b,c,i};
    }
    sort(que.begin(), que.end(), comp1);
    int l = 0, r = 0;
    tab[0] = 1e9;
    while(l != n or r != p){
        if(l != n and (r == p or wec[l][1] <= que[r][0])){
            for(int j = 100'000 - wec[l][0]; j >= 0; j--){
                tab[wec[l][0] + j] = max(tab[wec[l][0] + j], min(tab[j], wec[l][2]));
            }
            l++;
        }else{
            if(tab[que[r][1]] > que[r][0] + que[r][2]){
                res[que[r][3]] = true;
            }else{
                res[que[r][3]] = false;
            }
            r++;
        }
    }
    for(int i = 0; i < p; i++){
        if(res[i]) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
