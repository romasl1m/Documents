#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
map<char, bool> mapa;
int main(){
    string s;
    cin >> s;
    int res = 0;
    for(char c : s){
        if(mapa[c]) continue;
        mapa[c] = true;
        res++;
    }
    if(res % 2 == 0){
        cout << "CHAT WITH HER!";
    }else{
        cout << "IGNORE HIM!";
    }
}
