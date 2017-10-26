struct Edge {
  int u, v, c, next;
} edge[2010];
int head[maxn], p[maxn], d[maxn];
bool vis[maxn], flag;
int tot;
void add_edge(int u, int v, int c) {
  edge[tot] = {u, v, c, head[u]};
  head[u] = tot++;
}
void spfa(int u) {
  int v;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    v = edge[i].v;
    if (d[u] + edge[i].c < d[v]) {
      if (vis[v]) {  //存在一点在一条路径上出现多次
        flag = true;
        return;
      } else {
        d[v] = d[u] + edge[i].c;
        vis[v] = true;
        spfa(v);
      }
    }
  }
}
