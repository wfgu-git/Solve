/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;
const int moder = 1e9 + 7;

struct point {
  int x, y;
} ;
vector<point> pt;
map<int, int> hsx, hsy;
int fa[maxn];
int point_cont[maxn];
int edge_cont[maxn];
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
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
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    static int px, py;
    cin >> px >> py;
    pt.push_back({px, py});
  }
  int tot = 0;
  for (point & p : pt) {
    if (!hsx.count(p.x)) {
      hsx.insert({p.x, tot++});
    }
    if (!hsy.count(p.y)) {
      hsy.insert({p.y, tot++});
    }
  }
  for (int i = 0; i < tot; ++i) {
    fa[i] = i;
  }
  for (point & p : pt) {
    fa[find(hsx[p.x])] = find(hsy[p.y]);
  }
  for (point & p : pt) {
    point_cont[find(hsx[p.x])]++;
  }
  for (int i = 0; i < tot; ++i) {
    edge_cont[find(i)]++;
  }
  ll ans = 1LL;
  for (int i = 0; i < tot; ++i) {
    if (i == find(i)) {
      if (point_cont[i] == edge_cont[i] - 1) {
        ans = ans * (mod_pow(2, edge_cont[i]) - 1LL) % moder;
      } else {
        ans = ans * mod_pow(2, edge_cont[i]) % moder;
      }
    }
  }
  cout << ans;
}
