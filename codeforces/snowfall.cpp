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
    int t;
    cin >> t;
    cookie(t){
        int n;
        cin >> n;
        vector<long long> six, three,e, N;
        droptop(0,n){
            long long a;
            cin >> a;
            if(a % 6 == 0){
                six.push_back(a);
            }else if(a % 2 == 0){
                e.push_back(a);
            }else if(a % 3 == 0){
                three.push_back(a);
            }else{
                N.push_back(a);
            }
        }
        for(long long x : e){
            cout << x << " ";
        }
        for(long long x : N){
            cout << x << " ";
        }
        for(long long x : three){
            cout << x << " ";
        }
        for(long long x : six){
            cout << x << " ";
        }
        cout << "\n";
    }
}

