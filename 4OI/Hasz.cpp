#include <iostream>
#include <string>
using namespace std;
const int maks = 1e9 + 7;
const int base = 27;
long long hasz(const string &s) {
    long long h = 0;
    for (char c : s) {
        h = ((h * base) % maks + c) % maks;
    }
    return h;
}
int main(){
  string s;
  cin >> s;
  cout << hasz(s);
}