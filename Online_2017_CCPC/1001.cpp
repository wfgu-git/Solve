#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 20;
vector<int> G[maxn];
int N, M;
bool used[maxn];
int D[maxn];
int deg[maxn];
int Its() {
  int ans = 0;
  memset(used, 0, sizeof(used));
  memcpy(deg, D, sizeof(D));
  while (true) {
    int mx = -1, u;
    for (int i = 1; i <= N; ++i) {
      if (used[i]) continue;
      if (deg[i] >= mx) {
        mx = deg[i];
        u = i;
      }
    }
    if (mx <= 0) break;
    ++ans;
    used[u] = true;
    for (const int& v : G[u]) --deg[v];
  }
  return ans;
}
int Hack() {
  int ans = 0;
  memset(used, 0, sizeof(used));
  memcpy(deg, D, sizeof(D));
  while (true) {
    int mx = -1, u;
    for (int cont = 1000; cont >= 0; --cont) {
      int i = rand() % N + 1;
      if (used[i]) continue;
      if (deg[i] >= mx) {
        mx = deg[i];
        u = i;
      }
    }
    if (mx <= 0) break;
    ++ans;
    used[u] = true;
    for (const int& v : G[u]) --deg[v];
  }
  return ans;
}

int main() {
  srand(time(0));
  freopen("/home/wfgu/solve/data.out", "r", stdin);
  int kase = 0;
  int T;
  cin >> T;
  while (T--) {
    // Graph();
    scanf("%d%d", &N, &M);
    memset(D, 0, sizeof(D));
    for (int i = 0; i < M; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      D[u]++; D[v]++;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int me = 0x3f3f3f3f;
    for (int i = 0; i < 1000; ++i) {
      me = min(me, Hack());
    }
    // cout << Its() / me << endl;
    if (me * 3 <= Its()) {
      printf("case  #%d\n", ++kase);
    }
  }
  return 0;
}
