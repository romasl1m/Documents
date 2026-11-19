#include <iostream>
using namespace std;
int main(){
    srand(time(NULL));
    // int n = rand() % 101;
    int n = rand() % 300'001;
    while(n < 2){
        n = rand() % 300'001;
    }
    cout << 1 << " " << n << endl;
    for(int i = 2; i <= n; i++){
        int x = rand() % i;
        while(x == i or x == 0){
            x = rand() % i;
        }
        cout << x << " ";
    }
    cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << rand() %  2 << " ";
    // }
    return 0;
}
