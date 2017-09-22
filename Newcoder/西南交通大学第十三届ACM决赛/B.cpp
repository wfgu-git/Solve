/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 500 + 20;
struct query {
  int row, k, v;
} ;
vector<query> Qs;
bool elem[maxn][maxn];
int mark[2][maxn];
int ans[maxn][maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    Qs.clear();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
      int opt, k, v;
      scanf("%d%d%d", &opt, &k, &v);
      Qs.push_back({opt % 2, k, v});
    }
    int row, k, v;
    memset(ans, 0, sizeof(ans));
    memset(mark, 0, sizeof(mark));
    memset(elem, 0, sizeof(elem));
    for (vector<query>::reverse_iterator it = Qs.rbegin(); it != Qs.rend(); ++it) {
      row = it->row;
      k = it->k;
      v = it->v;

      if (mark[row][k]) {
        continue;
      }

      mark[row][k] = 1;
      if (row) {
        for (int i = 1; i <= n; ++i) {
          if (elem[k][i]) {
            continue;
          }
          elem[k][i] = 1;
          ans[k][i] = v;
        }
      } else {
        for (int i = 1; i <= n; ++i) {
          if (elem[i][k]) {
            continue;
          }
          elem[i][k] = 1;
          ans[i][k] = v;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        printf("%d%c", ans[i][j], j < n ? ' ' : '\n');
      }
    }
  }
  return 0;
}
