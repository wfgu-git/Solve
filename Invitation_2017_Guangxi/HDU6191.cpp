/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct Node {
  Node* ch[2];
  Node() {
    ch[0] = ch[1] = nullptr;
  }
} ;
int ans[maxn], val[maxn], N, Q;
vector<int> G[maxn];
vector<pii> qry[maxn];
Node* root[maxn];
void insert(Node* o, int x) {
  int tid;
  for (int i = 31; i >= 0; --i) {
    tid = 0;
    if (x & (1 << i)) tid = 1;
    if (o->ch[tid] == nullptr) {
      Node* tmp = new Node();
      o->ch[tid] = tmp;
    }
    o = o->ch[tid];
  }
}
int query(Node* o, int x) {
  int ret = 0;
  int tid;
  for (int i = 31; i >= 0; --i) {
    tid = 0;
    if (x & (1 << i)) tid = 1;
    if (o->ch[tid ^ 1] != nullptr) {
      o = o->ch[tid ^ 1];
      ret |= (1 << i);
    } else {
      o = o->ch[tid];
    }
  }
  return ret;
}
Node* unite(Node *p, Node* q) {
  if (p == nullptr) return q;
  if (q == nullptr) return p;
  p->ch[0] = unite(p->ch[0], q->ch[0]);
  p->ch[1] = unite(p->ch[1], q->ch[1]);
  delete q;
  return p;
}
void dfs(int u) {
  int v;
  root[u] = new Node();
  insert(root[u], val[u]);
  for (int i = 0; i < G[u].size(); ++i) {
    v = G[u][i];
    dfs(v);
    root[u] = unite(root[u], root[v]);
  }
  for (int i = 0; i < qry[u].size(); ++i) {
    ans[qry[u][i].second] = query(root[u], qry[u][i].first);
  }
}
void del(Node* o) {
  if (o == nullptr) return;
  if (o->ch[0] != nullptr) del(o->ch[0]);
  if (o->ch[1] != nullptr) del(o->ch[1]);
  delete o;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &Q) != EOF) {
    for (int i = 1; i <= N; ++i) {
      G[i].clear();
      qry[i].clear();
      scanf("%d", val + i);
    }
    for (int i = 2; i <= N; ++i) {
      int x;
      scanf("%d", &x);
      G[x].push_back(i);
    }
    for (int i = 0; i < Q; ++i) {
      int v, x;
      scanf("%d%d", &v, &x);
      qry[v].push_back({x, i});
    }
    dfs(1);
    for (int i = 0; i < Q; ++i) {
      printf("%d\n", ans[i]);
    }
    // for (int i = 1; i <= N; ++i) del(root[i]);
    del(root[1]);
  }
  return 0;
}
