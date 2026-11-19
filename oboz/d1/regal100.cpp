#include <iostream>
#include <queue>
#include <vector>
using namespace std;
long long tab[200'001];
int main(){
  long long d,n;
  cin >> d >> n;
  priority_queue<long long, vector<long long>, greater<long long>> q;
  for(int i = 1; i <= n; i++){
    cin >> tab[i];
    q.push(tab[i]);
  }
  long long res = 0;
  while(q.size() > 1){
    long long t1 = q.top();
    q.pop();
    long long t2 = q.top();
    q.pop();
    res += t1 + t2;
    q.push(t1 + t2);
  }
  cout << res << " ";
}

