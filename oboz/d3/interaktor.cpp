#include <bits/stdc++.h>
#include "solve_dlazaw.hpp"

using namespace std;
using namespace Solve;

double final_score(int cnt, int t) { 
    if (t==1) {
        if (cnt<30) return 1;
        else if (cnt<300) return min(1.0,30./cnt);
        else return 0.1;
    }
    else {
        if (cnt<2024) return 1;
        else if (cnt<5000) return min(1.0,pow(2024./cnt,max(1.0,4000./cnt)));
        else if (cnt<10000) return min(0.4,pow(2024./cnt,1.2));
        else return 0.1;
    }
    return 0; 
}

const int MAXN=500,MAXM=500;
long long int tab[MAXN][MAXM];
int n,m,t,query_cnt;

int drow[]={ -1, -0, +0, +1 };
int dcol[]={ -0, -1, +1, +0 };
bool check_saddle (int row, int col) {
    for (int i=0; i<4; i++) {
        int r=row+drow[i],c=col+dcol[i];
        if ((r<0)||(r>=n)||(c<0)||(c>=m)) continue;
        if (tab[r][c]==0) return false;
        if (tab[r][c]<=tab[row][col]) return false;
    }
    return true;
}
bool check_adjacent (int row, int col) {
    for (int i=0; i<4; i++) {
        int r=row+drow[i],c=col+dcol[i];
        if ((r<0)||(r>=n)||(c<0)||(c>=m)) continue;
        if (tab[r][c]==0) continue;
        if (check_saddle(r,c)==true) return false;
    }
    return true;
}

long long int num=1e11,num2=1e6;
vector <int> perm;

int cnt=0;
long long int value (int row, int col) {
    return tab[row][col];
}

int main(int argc, char** argv) {
	auto& I = Interactor::create(argc, argv);
	auto& input = I.test_reader();
	
	auto end = [&] (int score, const std::string& msg) {
		I.end(score, msg);
	};
    input >> t >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            input >> tab[i][j] ;
        }
    }
    
    I.writer(0) << t << ' ' << n << ' ' << m << endl; 
    while(true) {
        char co; 
        I.reader(0) >> co;
        if(co == '?') {
            int row, col;
            I.reader(0) >> row >> col; 
            row--; col--;
            if ((row<0)||(row>=n)||(col<0)||(col>=m)) end(0, "zapytanie o pole spoza planszy");
            query_cnt++; 
            if (query_cnt>n*m) end(0, "wykonano ponad n * m zapytań typu ?");
            long long sth = value(row, col);
            I.writer(0) << sth << endl; 
        }
        else if(co == '!') {
            int row, col;
            I.reader(0) >> row >> col; 
            row--;col--;
            if ((row<0)||(row>=n)||(col<0)||(col>=m)) end(0, "wynik powinien należeć do planszy");
            if (check_saddle(row,col)==false) end(0, "WA");
            break;
        }
        else {
            end(0, "zapytanie powinno być typu ? lub !");
        }
    }

    end(100. * final_score(query_cnt, t), "AC: " + to_string(query_cnt) + " zapytań");
    
    return 0;
}
