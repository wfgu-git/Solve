/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;

int n, Q;
vector<int> origin_tree[maxn];
vector<int> virtual_tree[maxn];
vector<int> key_node;
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    static int u, v;
    cin >> u >> v;
    origin_tree[u].push_back(v);
    origin_tree[v].push_back(u);
  }
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      int v;
      cin >> v;
      key_node.push_back(v);
    }
  }
}
