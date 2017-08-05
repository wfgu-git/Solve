int used[maxn];
int topo[maxn], tot;
bool dfs(int u) {
  used[u] = -1; // 正在访问
  for (int v = 0; v < n; ++v) if (G[u][v]) {
    if (used[v] < 0) return false; // 存在有向环
    else if (!used[v] && !dfs(v)) return false;
  }
  used[u] = 1; topo[--tot] = u;
  return true;
}
bool toposort() {
  tot = n;
  memset(used, 0, sizeof(used));
  for (int u = 0; u < n; ++u) if (!used[u]) {
    if (!dfs(u)) return false;
  }
  return true;
}
