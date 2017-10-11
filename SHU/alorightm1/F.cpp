/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int n;
vector<pii> G[maxn];
int dist[maxn], step[maxn];
bool vis[maxn];
void SPFA(int s, int n) {
  for (int i = 0; i < n; ++i) {
    step[i] = 0;
    dist[i] = inf;
    vis[i] = 0;
  }
  queue<int> Q;
  Q.push(s);
  dist[s] = 0;
  step[s] = 0;
  vis[s] = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    vis[u] = 0;
    for (pii x : G[u]) {
      int v = x.first;
      int d = x.second;
      if (dist[u] + d < dist[v]) {
        dist[v] = dist[u] + d;
        step[v] = step[u] + 1;
        if (!vis[v]) {
          Q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
}
void BFS(int s, int t) {
  memset(step, -1, sizeof(step));
  step[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (pii x : G[u]) {
      int v = x.first;
      if (step[v] == -1 || step[v] > step[u] + 1) {
        step[v] = step[u] + 1;
        Q.push(v);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int kase = 0;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      G[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        if (x != -1) {
          G[i].push_back({j, x});
        }
      }
    }
    int s, t;
    cin >> s >> t;
    --s; --t;
    SPFA(s, n);
    cout << "Case " << ++kase << '\n' << dist[t] << " " << step[t] << endl;
  }
}
