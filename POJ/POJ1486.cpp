/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 2000;
struct Max_Match {
  int n;
  bool g[maxn][maxn];
  bool vis[maxn];
  int left[maxn];

  void init(int n) {
    this->n = n;
    memset(g, 0, sizeof(g));
    memset(left, -1, sizeof(left));
   }
  bool dfs(int u) {
    for (int v = n; v < 2 * n; ++v) if(g[u][v] && !vis[v]) {
      vis[v] = true;
      if (left[v] == -1 || dfs(left[v])) {
        left[v] = u;
        return true;
      }
    }
    return false;
  }
  int solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      memset(vis,0,sizeof(vis));
      if (dfs(i)) ++ans;
    }
    return ans;
  }
} MM;
int N;
int xmax[maxn], xmin[maxn], ymin[maxn], ymax[maxn];
int numx[maxn], numy[maxn];
bool comp(const pair<char, int>&x, const pair<char, int>& y) {
  return x.first < y.first;
}
void work(int cas) {
  /*
  left 0 ~ N - 1 (A.B.C.D.E...)
  right N ~ 2 * N - 1 (1, 2, 3, 4, 5...)
  */
  MM.init(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d%d%d%d", xmin + i, xmax + i, ymin + i, ymax + i);
  }
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", numx + i, numy + i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (numx[j] > xmin[i] && numx[j] < xmax[i] && numy[j] > ymin[i] && numy[j] < ymax[i]) {
        MM.g[i][j + N] = 1;
      }
    }
  }

  printf("Heap %d\n", cas);
  int tmp = MM.solve();
  if (tmp != N) {
    puts("none");
    return;
  }

  vector<pair<char, int> > ans;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (numx[j] > xmin[i] && numx[j] < xmax[i] && numy[j] > ymin[i] && numy[j] < ymax[i]) {
        MM.g[i][j + N] = 0;
        memset(MM.left, -1, sizeof(MM.left));
        if (MM.solve() < tmp) {
          ans.push_back(make_pair((char)'A' + i, j + 1));
        }
        MM.g[i][j + N] = 1;
      }
    }
  }
  if (ans.size()) {
    sort(ans.begin(), ans.end(), comp);
    for (int i = 0; i < ans.size(); ++i) {
      pair<char, int> x = ans[i];
      printf("(%c,%d)%c", x.first, x.second, (i < ans.size() - 1 ? ' ' : '\n'));
    }
  } else {
    puts("none");
  }
  printf("\n");
}
int kase = 0;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d", &N) != EOF && N) {
    work(++kase);
  }
  return 0;
}
