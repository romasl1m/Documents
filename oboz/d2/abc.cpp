#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, podzadanie;
    cin >> n >> podzadanie;
    cout << "? " << 1 << " " << n << endl;
    string ans;
    cin >> ans;
    if(ans == "TAK"){
        cout << "! " << 1 << " " << 2 << endl;
    }
    else{
        cout << "! " << 1 << " " << n << endl;
    }
}