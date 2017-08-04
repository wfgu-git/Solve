#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;
int love[maxn][maxn];
int ex_girl[maxn];
int ex_boy[maxn];
bool vis_girl[maxn];
bool vis_boy[maxn];
int match[maxn];
int slack[maxn];
int n;
bool dfs(int girl) {
  vis_girl[girl] = true;
  for (int boy = 0; boy < n; ++boy) {
    if (vis_boy[boy]) continue;
    int d = ex_girl[girl] + ex_boy[boy] - love[girl][boy];
    if (d == 0) {
      vis_boy[boy] = true;
      if (match[boy] == -1 || dfs(match[boy])) {
        match[boy] = girl;
        return true;
      }
    } else {
      slack[boy] = min(slack[boy], d);
    }
  }
  return false;
}
void KM() {
  memset(match, -1, sizeof(match));
  memset(ex_boy, 0, sizeof(ex_boy));
  for (int i = 0; i < n; ++i) {
    ex_girl[i] = love[i][0];
    for (int j = 1; j < n; ++j) {
      ex_girl[i] = max(ex_girl[i], love[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(slack, slack + n, inf);
    while (true) {
      memset(vis_girl, 0, sizeof(vis_girl));
      memset(vis_boy, 0, sizeof(vis_boy));
      if (dfs(i)) break;
      int d = inf;
      for (int j = 0; j < n; ++j) {
        if (!vis_boy[j]) d = min(d, slack[j]);
      }
      for (int j = 0; j < n; ++j) {
        if (vis_girl[j]) ex_girl[j] -= d;
        if (vis_boy[j]) ex_boy[j] += d;
        else slack[j] -= d;
      }
    }
  }
  /*
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += love[match[i]][i];
  }
  return ret;
  */
}
pair<int, int> px[maxn];
pair<int, int> py[maxn];
void read(pair<int, int> *p) {
  for (int i = 0; i < n; ++i) {
    static int x, y;
    scanf("%d%d", &x, &y);
    p[i] = {x, y};
  }
}
int square(int a) {return a * a;}
int calc_dis(pair<int, int> &a, pair<int, int> &b) {
  return square(a.first - b.first) + square(a.second - b.second);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    read(px);
    read(py);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        love[j][i] = -1 * calc_dis(px[i], py[j]);
      }
    }
    KM();
    // cout << "!!!" << endl;
    for (int i = 0; i < n; ++i) {
      printf("%d\n", match[i] + 1);
    }
  }
  return 0;
}
