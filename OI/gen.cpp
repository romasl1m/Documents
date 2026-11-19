#include <iostream>
using namespace std;
int main(){
    srand(time(NULL));
    int n = rand() % 6;
    int m = rand() % 10;
    cout << n << " " << m << endl;
    for(int i = 1; i <= m; i++){
        int a,b;
        a = rand() % (n + 1);
        b = rand() % (n + 1);
        cout << a << " "<< b << "\n";
    }
    return 0;
}
