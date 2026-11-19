#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int tab[1001][1001];
int twos[1001][1001];
int fives[1001][1001];
char path2[1001][1001];
char path5[1001][1001];
int div2(int x){
    if(x == 0) return 1;
    int res = 0;
    while(x % 2 == 0){
        res++;
        x >>= 1;
    }
    return res;
}
int div5(int x){
    if(x == 0) return 1;
    int res = 0;
    while(x % 5 == 0){
        res++;
        x /= 5;
    }
    return res;
}
int main(){
    raindrop
    int n;
    cin >> n;
    int zx = -1, zy = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tab[i][j];
            if(tab[i][j] == 0){
                zx = i; zy = j;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            twos[i][j] = 1e9;
            fives[i][j] = 1e9;
        }
    }
    twos[1][1] = div2(tab[1][1]);
    fives[1][1] = div5(tab[1][1]);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 and j == 1) continue;
            int c2 = div2(tab[i][j]);
            int c5 = div5(tab[i][j]);
            if(twos[i - 1][j] < twos[i][j - 1]){
                twos[i][j] = twos[i - 1][j] + c2;
                path2[i][j] = 'D';
            }else{
                twos[i][j] = twos[i][j - 1] + c2;
                path2[i][j] = 'R';
            }
            if(fives[i - 1][j] < fives[i][j - 1]){
                fives[i][j] = fives[i - 1][j] + c5;
                path5[i][j] = 'D';
            }else{
                fives[i][j] = fives[i][j - 1] + c5;
                path5[i][j] = 'R';
            }
        }
    }
    int res = min(twos[n][n], fives[n][n]);
    if(zx != -1 and res > 1){
        cout << 1 << "\n";
        for(int i = 1; i < zx; i++) cout << 'D';
        for(int j = 1; j < zy; j++) cout << 'R';
        for(int i = zx; i < n; i++) cout << 'D';
        for(int j = zy; j < n; j++) cout << 'R';
        return 0;
    }
    cout << res << "\n";
    string s;
    int i = n, j = n;
    if(twos[n][n] < fives[n][n]){
        while(i > 1 or j > 1){
            s += path2[i][j];
            if(path2[i][j] == 'D') i--;
            else j--;
        }
    }else{
        while(i > 1 or j > 1){
            s += path5[i][j];
            if(path5[i][j] == 'D') i--;
            else j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}
