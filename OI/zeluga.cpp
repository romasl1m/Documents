#include <bits/stdc++.h>
using namespace std;
struct p {
    int x, y,idx;
};
int bit;
vector<long long> cur, sum;
void update(int idx, long long c, long long s){
    for(int i = idx; i < bit; i += i & -i){
        cur[i] += c;
        sum[i] += s;
    }
}
pair<long long,long long> f(int idx){
    long long c = 0, s = 0;
    for(int i = idx; i > 0; i -= i & -i){
        c += cur[i];
        s += sum[i];
    }
    return {c, s};
}
pair<long long,long long> fsuf(int idx){
    pair<long long, long long> total = f(bit - 1);
    pair<long long, long long> pre = f(idx - 1);
    return {total.first - pre.first, total.second - pre.second};
}
bool comp(p a, p b){
  if(a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool comp2(p a, p b){
  if(a.x != b.x) return a.x > b.x;
  return a.y > b.y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<p> tab(n);
    vector<int> ys(n);
    for(int i = 0; i < n; i++){
        cin >> tab[i].x >> tab[i].y;
        tab[i].idx = i;
        ys[i] = tab[i].y;
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end()); 
    for(int i=0;i<n;i++) tab[i].y = lower_bound(ys.begin(), ys.end(), tab[i].y) - ys.begin() + 1;
    vector<long long> low(n, 0), high(n, 0);
    bit = ys.size() + 2;
    cur.assign(bit, 0);
    sum.assign(bit, 0);
    sort(tab.begin(),tab.end(), comp);
    for(int i = 0; i < n; i++){
        pair<long long,long long> c = f(tab[i].y);
        low[tab[i].idx] = c.second + c.first;
        update(tab[i].y, c.first + 1, c.second + c.first + 1);
    }
    cur.assign(bit, 0);
    sum.assign(bit, 0);
    sort(tab.begin(),tab.end(), comp2);
    for(int i = 0; i < n; i++){
        pair<long long,long long> c = fsuf(tab[i].y);
        high[tab[i].idx] = c.second + c.first;
        update(tab[i].y, c.first + 1, c.second + c.first + 1);
    }
    for(int i = 0; i < n; i++){
        cout << low[i] + high[i] << "\n";
    }
}
