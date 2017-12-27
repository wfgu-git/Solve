
 /*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 500000 + 20;

vector<vector<int> > g;
vector<int> state[maxn], depth[maxn];
int dfn, in[maxn], out[maxn];
string ch;
void dfs(int x, int d) {
  in[x] = ++dfn;

  int temp = state[d].back();
  temp ^= 1 << (ch[x] - 'a');
  state[d].push_back(temp);
  depth[d].push_back(dfn);

  for (int v : g[x]) {
    dfs(v, d + 1);
  }
  out[x] = dfn;
}
int find_l(int h, int x) {
  int lb = 0;
  int ub = depth[h].size() - 1;
  int ans = -1;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (depth[h][mid] >= x) {
      ans = mid;
      ub = mid - 1;
    } else {
      lb = mid + 1;
    }
  }
  return ans;
}
int find_r(int h, int x) {
  int lb = 0;
  int ub = depth[h].size() - 1;
  int ans = -1;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (depth[h][mid] <= x) {
      ans = mid;
      lb = mid + 1;
    } else {
      ub = mid - 1;
    }
  }
  return ans;
}
void work() {
  int n, m;
  cin >> n >> m;
  g.resize(n);

  for (int i = 0; i < n; ++i) {
    state[i].push_back(0);
    depth[i].push_back(0);
  }

  for (int i = 1; i < n; ++i) {
    int fa;
    cin >> fa;
    g[fa - 1].push_back(i);
  }
  cin >> ch;

  dfs(0, 0);

  for (int i = 0; i < m; ++i) {
    int v, h;
    cin >> v >> h;
    --v; --h;
    int l = find_l(h, in[v]);
    int r = find_r(h, out[v]);
    int ret = 0;
    if (l != -1 && r != -1) {
      ret = state[h][r] ^ state[h][l - 1];
    }
    ret = __builtin_popcount(ret);
    if (ret > 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
