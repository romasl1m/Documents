#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> wec;
int main(){
  int t;
  cin >> n >> t;
  wec.resize(n);
  for(int i = 0; i < n; i++){
    wec[i] = i + 1;
  }
  while(wec.size() > 2){
    int mid = wec.size() / 3;
    if(mid == 0) break;
    int mod = wec.size() % 3;
    if(mod == 0){
      // cout << "END";
      cout << "? " << (mid << 1) << " ";
      for(int i = 0; i < (mid << 1); i++){
        cout << wec[i] << " ";
      }
      cout << "\n" << flush;
      string s;
      cin >> s;
      if(s == "TAK"){
        wec.erase(wec.begin() + (mid << 1), wec.end());
      }else{
        cout << "? " << wec.size() - mid << " ";
        for(int i = mid; i < wec.size(); i++){
          cout << wec[i] << " ";
        }
        cout << "\n" << flush;
        string s1;
        cin >> s1;
        cout << flush;
        if(s1 == "TAK"){
          wec.erase(wec.begin(), wec.begin() + mid);
        }else{
          wec.erase(wec.begin() + mid, wec.begin() + (mid << 1));
          // cout << "LAST" << mid << " " << mid * 2;
        }
      }
    }else if(mod == 1){
      cout << "? " << (mid << 1) + 1 << " ";
      for(int i = 0; i <= (mid << 1); i++){
        cout << wec[i] << " ";
      }
      cout << "\n" << flush;
      string s;
      cin >> s;
      if(s == "TAK"){
        wec.erase(wec.begin() + (mid << 1) + 1, wec.end());
      }else{
        cout << "? " << wec.size() - mid << " ";
        for(int i = mid; i < wec.size(); i++){
          cout << wec[i] << " ";
        }
        cout << "\n" << flush;
        string s1;
        cin >> s1;
        // cout << flush;
        cout << flush;
        if(s1 == "TAK"){
          wec.erase(wec.begin(), wec.begin() + mid);
        }else{
          // for(int i = mid; i <= mid * 2; i++){
          //   cout << wec[i] << " ";
          // }
          wec.erase(wec.begin() + mid, wec.begin() + (mid << 1)); 
        }
      } 
    }else{

      cout << "? " << ((mid + 1) << 1) << " ";
      for(int i = 0; i <= (mid << 1) + 1; i++){
        cout << wec[i] << " ";
      }
      cout << "\n" << flush;
      string s;
      cin >> s;
      if(s == "TAK"){
        wec.erase(wec.begin() + (mid << 1) + 2, wec.end());
      }else{
        cout << "? " << wec.size() - mid << " ";
        for(int i = mid; i < wec.size(); i++){
          cout << wec[i] << " ";
        }
        cout << "\n" << flush;
        string s1;
        cin >> s1;
        cout << flush;
        if(s1 == "TAK"){
          wec.erase(wec.begin(), wec.begin() + mid);
        }else{
          wec.erase(wec.begin() + mid, wec.begin() + (mid << 1)); 
        }
      } 
    }
  }
  cout << "! " << wec[0] << " " << wec[1];
  cout << flush;
  return 0;
}
