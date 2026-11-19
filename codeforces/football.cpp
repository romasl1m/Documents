#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool comp(int a, int b) { return a < b; }
#define raindrop                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);
#define droptop(a, n) for (int i = (a); i < (n); i++)
#define cookie(t) while (t--)
#define hotbox(wec) sort(wec.begin(), wec.end(), comp);
int main() {
  raindrop;
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  droptop(0, w) {
    long long cur = p - (i * d);
    // cout << i << " " << cur << endl;
    if (cur < 0 or cur % w != 0) {
      continue;
    }
    if (i + (cur / w) > n) {
      continue;
    }
    cout << cur / w << " " << i << " " << n - i - cur / w;
    return 0;
  }
  cout << -1;
  return 0;
}
