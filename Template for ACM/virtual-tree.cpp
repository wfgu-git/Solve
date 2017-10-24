void build(vector<int>& V) {
  sort(V.begin(), V.end(), comp);

  int top = 0, tot = 0;
  S[top++] = 1;
  for (int i = 0; i < k; ++i) {
    int v = V[i];
    int lca = get_lca(v, S[top - 1]);
    key_node[v] = 1;
    if (!vis[v]) used[tot++] = v;
    vis[v] = 1;
    if (!vis[lca]) {
      vis[lca] = 1;
      used[tot++] = lca;
    }
    if (lca != S[top - 1]) {
      int x, y;
      while (top >= 2 && depth[S[top -2]] >= depth[lca]) {
        x = S[top - 2];
        y = S[top - 1];
        add_virtual_edge(x, y);
        --top;
      }

      if (S[top - 1] != lca) {
        x = lca;
        y = S[--top];
        add_virtual_edge(x, y);
        S[top++] = lca;
      }
    }
    S[top++] = v;
  }
  while (top > 1) {
    add_virtual_edge(S[top - 1], S[top - 2]);
    --top;
  }

  // work...

  for (int i = 0; i < tot; ++i) {
    virtual_tree[used[i]].clear();
    key_node[used[i]] = 0;
    vis[used[i]] = 0;
  }
  key_nodes.clear();
}

