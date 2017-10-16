/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

ll mod_pow(ll a, ll b) {
  ll ret = 1LL, base = a;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
struct Point {
  int x, y;
} ;
vector<Point> pt;
vector<pair<int, int> > vertical[maxn];
vector<pair<int, int> > horizontal[maxn];
vector<int> G[maxn];
bool used[maxn];
set<int> X, Y;
int component_size, sum_of_degree;
void dfs(int u) {
  used[u] = true;
  ++component_size;
  sum_of_degree += G[u].size();
  X.insert(pt[u].x);
  Y.insert(pt[u].y);
  for (int v : G[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  pt.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> pt[i].x >> pt[i].y;
  }
  vector<int> x, y;
  for (int i = 0; i < n; ++i) {
    x.push_back(pt[i].x);
    y.push_back(pt[i].y);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 0; i < n; ++i) {
    pt[i].x = lower_bound(x.begin(), x.end(), pt[i].x) - x.begin();
    pt[i].y = lower_bound(y.begin(), y.end(), pt[i].y) - y.begin();
  }
  for (int i = 0; i < n; ++i) {
    vertical[pt[i].x].emplace_back(pt[i].y, i);
    horizontal[pt[i].y].emplace_back(pt[i].x, i);
  }
  for (int x = 0; x < n; ++x) {
    sort(vertical[x].begin(), vertical[x].end());
    for (int i = 1; i < vertical[x].size(); ++i) {
      int a = vertical[x][i].second;
      int b = vertical[x][i - 1].second;
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
  for (int y = 0; y < n; ++y) {
    sort(horizontal[y].begin(), horizontal[y].end());
    for (int i = 1; i < horizontal[y].size(); ++i) {
      int a = horizontal[y][i].second;
      int b = horizontal[y][i - 1].second;
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    dfs(i);
    int k = mod_pow(2, X.size() + Y.size());
    if (sum_of_degree / 2 == component_size - 1) --k;
    ans = ans * k % moder;
    X.clear(); Y.clear();
    sum_of_degree = 0;
    component_size = 0;
  }
  cout << ans;
}
