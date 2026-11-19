#include <iostream> using namespace std; char tab[205][205]; int n,m; int main(){ cin >> n >> m; if(m <= 2 or n <= 2){ for(int i = 1; i <= m; i++){ tab[1][i] = '#'; } for(int i = 1; i <= n; i++){ tab[i][m] = '#'; } if(n > 2){ for(int i = 1; i <= m; i++){ tab[n][i] = '#'; } } for(int i = 1; i <= n; i++){ for(int j = 1; j <= m; j++){ if(tab[i][j] == '#'){ cout << '#'; }else{ cout << '.'; } } cout << "\n"; } return 0; } int x = 1, y = 1; tab[1][1] = '#'; int move = 1; int changed = 0; while(true){ changed = false; if(move == 2){ while(x < n and tab[x + 2][y] != '#'){ x++; // if(tab[x][y] == '#') changed = -1e9; changed++;
        tab[x][y] = '#';
      }
      move = 4;
    }else if(move == 1){
      while(y < m and tab[x][y + 2] != '#'){
        y++;
        changed++;
        tab[x][y] = '#';
      }
      move = 2;
    }else if(move == 3){
      while(x > 1 and tab[x - 2][y] != '#'){
        x--;
        changed++;
        tab[x][y] = '#';
      }
      move = 1;
    }else{
      while(y > 1 and tab[x][y - 2] != '#'){
        y--;
        changed++;
        tab[x][y] = '#';
      }
      move = 3;
    }
    if(changed <= 1) break;  
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(tab[i][j] == '#'){
        cout << '#';
      }else{
        cout << '.';
      }
    }
    cout << "\n";
  }
}
