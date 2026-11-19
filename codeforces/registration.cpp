#include <iostream>
#include <unordered_map>
using namespace std;
bool comp(int a, int b){
    return a < b;
}
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(a,n) for(int i = (a); i < (n); i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int count[100'001];
int hasb[100'001];
unordered_map<string,int> mapa;
int main(){
    raindrop;
    int n;
    cin >> n;
    cookie(n){
        string s;
        cin >> s;
        if(mapa[s] == 0){
            cout << "OK\n";
            mapa[s]++;
        }else{
            cout << s << mapa[s] << "\n";
            mapa[s]++;
        }
    }
}
