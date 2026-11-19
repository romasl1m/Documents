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
    raindrop;
    int n = 5;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int c;
            cin >> c;
            if(c == 1){
                cout << abs(i - 2) + abs(j - 2);
            }
        }
    }
    return 0;
}
