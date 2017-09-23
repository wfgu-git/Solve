/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int p[maxn];
int vis[maxn];
int b[maxn];
int id[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    memset(vis, 0, sizeof(vis));
    cin >> q;
    for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      vis[x] = 1;
    }
    int cont = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
      b[cont++] = p[i];
      id[cont - 1] = i;
    }
    int ans_aid, ans_bid;
    int sum, av, bv;
    int aid, bid;
    sum = av = bv = inf;
    for (int i = 0; i < cont; ++i) {
      int j = i + m - 1;
      if (j >= cont) continue;
      av = b[i];
      aid = id[i];
      for (int k = i + 1; k <= j; ++k) {
        if (b[k] < bv) {
          bv = b[k];
          bid = id[k];
        }
      }
      if (av + bv < sum) {
        ans_aid = aid;
        ans_bid = bid;
        sum = av + bv;
      }
      av = bv = inf;
    }
    cout << ans_aid << " " << ans_bid << endl;
  }
}
