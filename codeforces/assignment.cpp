#include <iostream>
#include <vector>
using namespace std;
#define raindrop ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define droptop(n) for(int i = 0; i < n; i++)
#define cookie(t) while(t--)
#define hotbox(wec) sort(wec.begin(), wec.end());
int tab[200'001];
bool wiz[200'001];
vector<int> wec[200'001];
int low[200'001], ssc[200'001], cur = 0, num = 0;//low,numer odwiedzenia
int ord[200'001], sccnumber[200'001];                                                 
int stackidx = 0;
const long long mod = 998244353;
vector<int> wecscc[200'001];
void tarjan(int w, int p){
    wiz[w] = true;
    ssc[w] = low[w] = ++cur;
    ord[++stackidx] = w;
    for(int ss : wec[w]){
        if(ss == p) continue;
        if(not ssc[ss]){
            tarjan(ss, w);
            low[w] = min(low[w], low[ss]);
        }
        else if(ss != p){
            low[w] = min(low[w], ssc[ss]);
        }
    }
    if(low[w] == ssc[w]){
        //nowa skladowa, zwiekszamy num(ber of sccs)
        num++;
        int x = 0;
        while(x != w){
            x = ord[stackidx--]; sccnumber[x] = num; // przechodzimy po stosie az nie bedzie pusty i wlaczamy wszystko co tam bylo do nowej scc poniewaz do zadnej innej nie naleza
            wecscc[num].push_back(x);//budujemy graf scc;                          
        }
    }
}
int color[200'001];//sprawdzamy czy graf jest dwudzielny
//graf jest dwudzielny iff da sie pogrupowac wierzcholki tak, aby krawedz laczyla rozne grupy, wtedy mozna przejsc miedzy kazdymi dwoma na 2 sposoby. sprawdzamy dla kazdej scc
bool check(int w, int colnew){
    if(~color[w]) return color[w] == colnew;//jest odwiedzony, to color musi byc ten sam co ostatni, else nie jest dwuspojny
    color[w] = colnew;
    for(int ss : wec[w]){
        if(sccnumber[w] == sccnumber[ss] and not check(ss, colnew ^ 1)){
            return false;
        }
    }
    return true;
}
int main(){
    raindrop;
    int t;
    cin >> t;
    cookie(t){
        int n,m,lim;
        cin >> n >> m >> lim;
        droptop(n){
            ssc[i + 1] = tab[i + 1] = low[i + 1] = sccnumber[i + 1] = ord[i + 1] = 0;
            wec[i + 1].clear();
            wecscc[i + 1].clear();
            color[i + 1] = -1;
            wiz[i + 1] = false;
            cin >> tab[i + 1];
        }
        num = cur = stackidx = 0;
        droptop(m){
            int a,b;
            cin >> a >> b;
            wec[a].push_back(b);
            wec[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(wiz[i]) continue;
            tarjan(i,-1);
        }
        int res = 1;
        for(int i = 1; i <= num; i++){
            int x = -1;
            for(int ss : wecscc[i]){
                if(tab[ss] < 0) continue;
                if(x < 0) x = tab[ss];//wartosc nowej skladowej, wszystkie musza byc takie same
                else if(x != tab[ss]){
                    //rozne wartosci w jednej skladowej, nie wyjdzie
                    res = 0;
                    break;
                }
            }
            if(res == 0) break;
            // for(int j = 1; j <= n; j++) color[j] = -1;
            bool f = check(wecscc[i][0],0);
            if(f){
                if(x < 0) res = (long long) res * lim % mod; //skladowa dwudzielna, mozemy ustawic dowolna wartosc do lim
            }else if(x > 0){
                res = 0;//nie dwudizelny, nie da sie
            }
            if(res == 0){
                break;
            }
        }
        cout << res << "\n";
    }
}

