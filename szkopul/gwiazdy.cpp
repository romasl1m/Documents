#include <iostream>
#include <vector>
using namespace std;
struct foot{
    int id; long long l,r,dif;
};
bool comp(foot a, foot b){
    return a.dif < b.dif;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
foot tab[500'001];
bool dir[500'001];
bool check(int pos, bool dir){
    bool cur = (tab[pos].l < tab[pos].r ? true : false);
    return cur == dir;
}
int main(){
    raindrop;
    int n,s;
    cin >> n >> s;
    droptop(0,n - 1){
        int a,b;
        cin >> a >> b;
        tab[i] = {i + 1,a,b,a-b};
    }
    droptop(0,n - 1){
        dir[i] = tab[i].l < tab[i].r ? false : true;
    }
    int lenl = 0, lenr = 0;
    while(lenl < n - 1 and not dir[lenl]) lenl++;
    while(lenr < n - 1 and dir[lenr]) lenr++;
    
    if(lenl >= s){
        int best = -1;   
        long long mindif = 2e18;
        droptop(0,s){
            if(tab[i].r - tab[i].l < mindif){
                mindif = tab[i].r - tab[i].l;
                best = i;
            }
        }
        if(best >= 0) dir[best] = true;
    }else if(lenr >= n - s + 1){
        int best = -1;
        long long mindif = 2e18;
        droptop(0, n - s + 1){
            if(tab[i].l - tab[i].r < mindif){
                mindif = tab[i].l - tab[i].r;
                best = i;
            } 
        }
        if(best >= 0) dir[best] = false;
    }

    long long res = 0;
    droptop(0,n - 1){
        if(dir[i]) res += tab[i].r;
        else res += tab[i].l;
    }

    vector<pair<bool,int>> block;
    if(n - 1 > 0){
        bool direction = dir[0];
        int cur = 1;
        droptop(1, n - 1){
            if(dir[i] == direction){
                cur++;
            }else{
                block.push_back({direction, cur});
                direction = dir[i];
                cur = 1;
            }
        }
        block.push_back({direction, cur});
    }


    vector<int> q = {s};
    int curmin = 1, curmax = n;
    for(auto [direction,len] : block){
        vector<int> temp; 
        droptop(0,len){
            if(not direction){
                if(curmin == s) curmin++;
                temp.push_back(curmin++);
            }else{
                if(curmax == s) curmax--;
                temp.push_back(curmax--);
            }
        }
        for(int i = len - 1; i >= 0; i--){
            q.push_back(temp[i]);
        }
    }
    cout << res << "\n";
    for(int i = 0; i < n; i++){
        cout << q[i] << " ";
    }
    return 0;
}
