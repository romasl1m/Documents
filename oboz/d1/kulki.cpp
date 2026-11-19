#include <iostream>
#include <vector>
using namespace std;
void f1(string& s, vector<string>& wec){
  string cur = wec[0];
  int len = cur.length();
  vector<int> q;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == cur[i % len]) continue;
    q.push_back(i);
  }
  int res = 0;
  while(not q.empty()){
  
  } 
}
void f2(string& s, vector<string>& wec){
  vector<bool> alf(30);
  for(string& s1 : wec){
    alf[s1[0] - 'a'] = true; 
  }
  deque<int> q;
  for(int i = 0; i < s.length(); i++){
    if(not alf[s[i] - 'a']){
      q.push_back(i);
    }
  }
  int used = n - 1;
  while(not q.empty()){
    int t = q.front();
    q.pop_front();
    if(q.front() - t > 4){
      q.pop_front();
    }else{
        while(){
        while(not alf[s[used] - 'a']) used--;
        q.push_back(used);
        used--;
      }
    }
  }
}
int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<string> wec(s);
  for(int i = 0; i < n; i++){
    cin >> wec[i];
  }
  if(n == 1){
    f1(s,wec);
  }else{
    f2(s,wec);
  }
}
