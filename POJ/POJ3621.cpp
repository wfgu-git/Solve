#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<pair<int, double> > G[maxn];
int w[maxn];
double dist[maxn];
bool used[maxn];
bool flag;
double mid;
int N, M;
void add_edge(int u, int v, double d) {
  G[u].push_back(make_pair(v, d));
}
void spfa(int u) {
  used[u] = true;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i].first;
    double d = 1.0 * w[v] - mid * G[u][i].second;
    if (dist[v] < dist[u] + d) {
      if (used[v]) {
        flag = true;
        return;
      } else {
        dist[v] = dist[u] + d;
        spfa(v);
      }
    }
  }
  used[u] = false;
}
bool check() {
  flag = false;
  memset(dist, 0, sizeof(dist));
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= N; ++i) {
    spfa(i);
    if (flag) return true;
  }
  return false;
}
inline void work() {
  for (int i = 1; i <= N; ++i) G[i].clear();
  for (int i = 1; i <= N; ++i) {
    scanf("%d", w + i);
  }
  for (int i = 0; i < M; ++i) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    add_edge(u, v, d);
  }
  double lb = 0, ub = 0x3f3f3f3f;
  for (int i = 0; i < 100; ++i) {
    mid = (lb + ub) / 2.0;
    if (check()) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.2f\n", lb);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
