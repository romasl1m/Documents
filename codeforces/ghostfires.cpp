#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> rgb(3);
const vector<char> tab = {'R','G','B'};
string s;
bool comp(int a, int b){
    if(rgb[a] == rgb[b]){
        int i = s.size() - 1;
        while(i >= 0){
            if(s[i] == tab[a]) return true;
            if(s[i] == tab[b]) return false;
            i--;
        }
    }
    return rgb[a] > rgb[b];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        s = "";
        for(int i = 0; i < 3; i++) cin >> rgb[i];
        char last = 'a';

        bool stop = false;
        for(int j = 0; j < 3; j++){
            vector<int> wec;
            for(int i = 0; i < 3; i++){
                if(last != tab[i] and rgb[i] > 0){
                    wec.push_back(i);
                }
            }
            if(wec.empty()){
                stop = true;
                cout << s << "\n";
                break;
            }
            sort(wec.begin(), wec.end(), comp);
            s.push_back(tab[wec[0]]);
            rgb[wec[0]]--;
            last = tab[wec[0]];
        }
        if(stop) continue;
        while(true){
            vector<int> wec;
            for(int i = 0; i < 3; i++){
                if(s[s.size() - 1] != tab[i] and s[s.size() - 3] != tab[i] and rgb[i] > 0){
                    // cout << "deb " << s << " " << tab[i] << " " << s[s.size() - 1] << " " << s[s.size() - 3] << endl;
                    wec.push_back(i);
                }//else if(s == "RGBGR"){
                //     cout << tab[i] << " is not ok here because " << s[s.size() - 1] << " and " << s[s.size() - 3] << " or the size " << rgb[i] << endl;
                // }
            }
            if(wec.empty()){
                cout << s << "\n";
                stop = true;
                break;
            }
            sort(wec.begin(), wec.end(), comp);
            s.push_back(tab[wec[0]]);
            rgb[wec[0]]--; 
            // cout << "and we add " << tab[wec[0]] << endl;
        }
        if(stop) continue;
        cout << s << "\n";
    }
}
