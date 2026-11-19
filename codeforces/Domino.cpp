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
int main(){
    int n,m;
    cin >> n >> m;
    if(n % 2 == 0){
        cout << (n >> 1) * m;
        return 0;
    }
    if(m % 2 == 0){
        cout <<  (m >> 1) * n;
        return 0;
    }
    cout << (n >> 1) * m + (m >> 1);
}
