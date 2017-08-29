#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
const int maxn = 5000;
using namespace std;
struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];  //节点数为 2 * n
  int S[maxn * 2], c;       // S为栈，用于反悔。c 为栈大小
  bool mark[maxn * 2];      //表示是否选中
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof mark);
  }
  /* others...
  a = b :
  (a xor b == 0)
    add_clause(a,0,b,1);
    add_clause(a,1,b,0);
  a != b :
    add_clause(a,0,b,0);
    add_clause(a,1,b,1);
  a = b = true :
    add_clause(a,0,b,1);
    add_clause(a,1,b,0);
    add_clause(a,1,b,1);
  a = b = false	:
    add_clause(a,0,b,1);
    add_clause(a,1,b,0);
    add_clause(a,0,b,0);
  */

  /*
  my...
  add_clause(x, xval ^ 1, y, yval ^ 1)  x和y有冲突
  */
  void add_clause(int x, int xval, int y, int yval) {
    x = (x * 2) + xval;
    y = (y * 2) + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }
  bool DFS(int x) {
    if (mark[x ^ 1]) return false;  //如果另一个节点已经被选，那么不能成立！
    if (mark[x]) return true;
    S[c++] = x;      //入栈
    mark[x] = true;  //选中
    for (int i = 0; i < G[x].size(); ++i) {
      if (!DFS(G[x][i]))
        return false;  //从当前点出发，沿着有向边标记所有能标记的节点
    }
    return true;
  }
  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {  //找到还没被标记的变量
        c = 0;                         //栈清空
        if (!DFS(i)) {  //如果尝试 false 不行，反悔到之前的情况，尝试 true
          while (c > 0) mark[S[--c]] = false;  //退栈，反悔
          if (!DFS(i + 1)) return false;
        }
      }
    }
    return true;
  }
} tsat;

/*
//挑战
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
struct Two_Sat {
  int V, n;
  bool flag;
  vector<int> G[maxn * 2 + 20];
  vector<int> rG[maxn * 2 + 20];
  vector<int> vs;
  bool used[maxn * 2 + 20];
  int comp[maxn * 2 + 20];
  void init(int V) {
    flag = true;
    this->V = 2 * V;
    this->n = V;
    for (int i = 1; i <= this->V; ++i) {
      G[i].clear();
      rG[i].clear();
    }
    memset(comp, 0, sizeof(comp));
  }

  void add_edge(int u, int v) {
    G[u].push_back(v);
    rG[v].push_back(u);
  }

  void DFS(int u) {
    used[u] = true;
    // for (const int& v : G[u]) {
    for (int i = 0; i < (int)G[u].size(); ++i) {
      int v = G[u][i];
      if (!used[v]) {
        DFS(v);
      }
    }
    vs.push_back(u);
  }

  void rdfs(int u, int k) {
    used[u] = true;
    comp[u] = k;
    // for (const int& v : rG[u]) {
    for (int i = 0; i < (int)rG[u].size(); ++i) {
      int v = rG[u][i];
      if (!used[v]) {
        rdfs(v, k);
      }
    }
  }

  int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 1; v <= V; ++v) {
      if (!used[v]) DFS(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    reverse(vs.begin(), vs.end());
    // for (int& x : vs) {
    for (int i = 0; i < (int)vs.size(); ++i) {
      int x = vs[i];
      if (!used[x]) rdfs(x, k++);
    }
    return k;
  }


  void run() {
    // ...
  }
} tsat;


*/
