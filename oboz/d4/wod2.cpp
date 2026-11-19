#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,a,b;

int q(int a, int a1, int b, int b1){
  cout << "? ";
  for(int i = 1; i < a; i++){
    cout << "0 ";
  } 
  for(int i = a; i <= a1; i++){
    cout << "1 ";
  }
  for(int i = a1 + 1; i < b; i++){
    cout << "0 ";
  }
  for(int i = b; i <= b1; i++){
    cout << "2 ";
  }
  for(int i = b1 + 1; i <= n; i++){
    cout << "0 ";
  }
  cout << "\n" << flush;
  int cur;
  cin >> cur;
  cout << flush;
  return cur;
}
int bins(int l, int r, int c){
  while(l < r){
    int mid = (l + r) >> 1;
    int cur = q(1,1,l,mid);
    if(cur != c * (mid - l + 1)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }
  return l;
}
void f(){
  int c = q(1,1,2,2);
  int sum = q(1,1,2,n);
  if(sum < c * (n - 1)){
    int w = bins(2,n,c);
    int a = q(1,1,w,w);
    cout << "! " << a << " " << c << "\n";
    cout << flush;
  }else if(sum >  c * (n - 1)){
    int w = bins(2,n,c);
    cout << "! " << c << " " << q(1,1,w,w) << "\n";
    cout << flush;
  }else{
    
  }
}
int main(){
  cin >> n;
  f(); 
  return 0;
}
