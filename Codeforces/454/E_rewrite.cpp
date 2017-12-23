/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 50;

int n, m;
vector<int> ans, temp;
int adj[maxn][maxn];
void dfs(int v) {
  if ((int)temp.size() >= (int)ans.size()) {
    return;
  }

  if (v == n) {
    for (int i = 0; i < n; ++i) {
      if (adj[n][i] != (1 << n) - 1) {
        return;
      }
    }
    ans = temp;
    return;
  }


  for (int i = 0; i < n; ++i) {
    adj[v + 1][i] = adj[v][i];
  }

  dfs(v + 1);
  
  temp.push_back(v);
  for (int i = 0; i < n; ++i) {
    if (adj[v][v] & (1 << i)) {
      adj[v + 1][i] |= adj[v][v];
    }
  }
  dfs(v + 1);
  temp.pop_back();
}
void work() {
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    adj[0][x] |= (1 << y);
    adj[0][y] |= (1 << x);
  }

  for (int i = 0; i < n; ++i) {
    ans.push_back(i);
    adj[0][i] |= (1 << i);
  }

  dfs(0);

  cout << ans.size() << "\n";
  for (int & x : ans) {
    cout << x + 1<< " ";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
