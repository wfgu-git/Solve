/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

vector<vector<int> > g;
string ch;
int dfn, in[maxn], out[maxn], arc[maxn];
vector<int> state[maxn], depth[maxn];
void dfs(int x, int d) {
  in[x] = ++dfn;
  arc[dfn] = x;
  int temp = state[d].empty() ? 0 : state[d].back();
  temp ^= 1 << (ch[x] - 'a');
  state[d].push_back(temp);
  depth[d].push_back(dfn);

  for (int v : g[x]) {
    dfs(v, d + 1);
  }

  out[x] = dfn;
}
void work() {
  int n, m;
  cin >> n >> m;
  g.resize(n);

  for (int i = 1; i < n; ++i) {
    int fa;
    cin >> fa;
    g[fa - 1].push_back(i);
  }
  cin >> ch;

  dfn = 0;
  dfs(0, 0);

  for (int i = 0; i < m; ++i) {
    int v, h;
    cin >> v >> h;
    --v;
    --h;
    auto lit = lower_bound(depth[h].begin(), depth[h].end(), in[v]);
    auto rit = lower_bound(depth[h].begin(), depth[h].end(), out[v]);
    if (lit == depth[h].end() && rit == depth[h].end()) {
      cout << "Yes\n";
      continue;
    }
    int l = lit - depth[h].begin();
    int r = rit - depth[h].begin();
    if (r && r == depth[h].size()) {
      r = depth[h].size() - 1;
    }
    int ret = state[h][r] ^ state[h][l] ^ (1 << (ch[arc[depth[h][l]]] - 'a'));
    // cout << "h = " << h + 1 << "   ";
    // cout << "l = " << l << "  r = " << r << "    ";
    // cout << ch[arc[depth[h][l]]] << "  " << ch[arc[depth[h][r]]] << endl;
    int flag = __builtin_popcount(ret);
    if (flag > 1) {
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
