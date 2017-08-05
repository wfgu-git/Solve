void euler(int u) {
  for (int v = 0; v < n; ++v) if (G[u][v] && !vis[u][v]) {
    vis[u][v] = vis[v][u] = 1;
    // vis[u][v] = 1;  // 有向图
    euler(v);
    st.push({u, v});
  }
}
