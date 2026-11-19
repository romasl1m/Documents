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
string fsum(const string &a, const string &b){
    string res = "";
    int reszta = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while(i >= 0 or j >= 0 or reszta){
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int sum = x + y + reszta;
        reszta = sum / 10;
        res.push_back((sum % 10) + '0');
        i--; j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
string fsub(const string &a, const string &b){
    string res = "";
    int reszta = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while(i >= 0 or j >= 0 or reszta){
        int x = (i >= 0 ? a[i] - '0' : 0);
        int y = (j >= 0 ? b[j] - '0' : 0);
        int sum = x - y - reszta;
        if(sum < 0){
            sum += 10;
            reszta = 1;
        }else{
            reszta = 0;
        }
        res.push_back(sum + '0');
        i--; j--;
    }
    reverse(res.begin(), res.end());
    return res;
}bool compare(const string &a, const string &b){
    if(a.length() > b.length()) return true;
    if(b.length() > a.length()) return false;
    for(int i = b.length() - 1; i >= 0; i--){
        if(a[i] - '0' == b[i] - '0') continue;
        return a[i] - '0' > b[i] - '0';
    }
    return true;
}
string lcd(string &a, string &b){
    if(a == "0") return b;
    if(b == "0") return a;
    int res = 0;    
    while(((a or b) & 1) == 0){
        a >>= 1; b >>= 1;
    }
}
int main(){
    raindrop;
    string n,k,l;
    if(not compare(l,k)) swap(l,k);
    string sum = fsum(k,l);
    string nwd = lcd(k,l);
    if(compare(fsub(sum,nwd),n)){
        sum = fsub(sum,n);
    }
}

