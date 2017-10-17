/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  int S[maxn * 2], c;
  bool mark[maxn * 2];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  void add_clause(int x, int xval, int y, int yval) {
    x = (x * 2) + xval;
    y = (y * 2) + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }
  bool DFS(int x) {
    if (mark[x ^ 1]) return false;  //如果另一个节点已经被选，那么不能成立！
    if (mark[x]) return true;
    S[c++] = x;      //入栈
    mark[x] = true;  //选中
    for (int i = 0; i < G[x].size(); ++i) {
      if (!DFS(G[x][i]))
        return false;  //从当前点出发，沿着有向边标记所有能标记的节点
    }
    return true;
  }
  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {  //找到还没被标记的变量
        c = 0;                         //栈清空
        if (!DFS(i)) {  //如果尝试 false 不行，反悔到之前的情况，尝试 true
          while (c > 0) mark[S[--c]] = false;  //退栈，反悔
          if (!DFS(i + 1)) return false;
        }
      }
    }
    return true;
  }
} tsat;
vector<int> str[maxn];
int len[maxn];
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  tsat.init(m + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> len[i];
    for (int j = 0; j < len[i]; ++j) {
      int x;
      cin >> x;
      str[i].push_back(x);
    }
  }
  /*
  0 : no change
  1 : change
  */
  for (int i = 1; i < n; ++i) {
    int x, y, pos = -1;
    int l = min(len[i], len[i + 1]);
    for (int j = 0; j < l; ++j) {
      if (str[i][j] != str[i + 1][j]) {
        pos = j;
        x = str[i][j];
        y = str[i + 1][j];
        if (x < y) {
          tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
        } else {
          tsat.add_clause(x, 0 ^ 1, y, 0 ^ 1);
          tsat.add_clause(x, 0 ^ 1, y, 1 ^ 1);
          tsat.add_clause(x, 1 ^ 1, y, 1 ^ 1);
        }
        break;
      }
    }
    if (pos == -1 && str[i].size() > str[i + 1].size()) {
      cout << "No";
      return 0;
    }
  }
  int flag = tsat.run();
  if (!flag) {
    cout << "No"; return 0;
  }
  cout << "Yes" << '\n';
  vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    if (tsat.mark[i * 2 + 1]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << " ";
  }
}
