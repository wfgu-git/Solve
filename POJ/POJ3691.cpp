#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 20;
const int chsz = 4;
struct Tire {
  int tot;
  int root;
  int fail[maxn], next[maxn][chsz], end[maxn];
  int getid(char c) {
    if (c == 'A') return 0;
    else if (c == 'T') return 1;
    else if (c == 'C') return 2;
    return 3;
  }
  int newnode() {
    for (int i = 0; i < chsz; ++i) {
      next[tot][i] = -1;
    }
    end[tot++] = 0;
    return tot - 1;
  }

  void init() {
    tot = 0;
    root = newnode();
  }

  void insert(const char* str) {
    int now = root;
    while (*str) {
      int chid = getid(*str);
      if (next[now][chid] == -1) next[now][chid] = newnode();
      now = next[now][chid];
      ++str;
    }
    ++end[now];
  }

  void build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < chsz; ++i) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
    }

    while (!q.empty()) {
      int now = q.front(); q.pop();
      for (int i = 0; i < chsz; ++i) {
        if (next[now][i] == -1) {
          next[now][i] = next[fail[now]][i];
        } else {
          fail[next[now][i]] = next[fail[now]][i];
          if (end[fail[next[now][i]]]) end[next[now][i]] = 1;
          q.push(next[now][i]);
        }
      }
    }
  }

  int solve(const char *str) {
    int ret = 0, k = 0;
    while (*str) {
      int chid = *str - 'a';
      k = next[k][chid];
      int j = k;
      while (j) {
        ret += end[j];
        end[j] = 0;
        j = fail[j];
      }
      ++str;
    }
    return ret;
  }

} AC;

const int inf = 0x3f3f3f3f;
int N;
int dp[1000 + 20][1000 + 20];
inline void work(int kase) {
  AC.init();
  static char buf[1000 + 20];
  for (int i = 0; i < N; ++i) {
    scanf("%s", buf);
    AC.insert(buf);
  }
  AC.build();
  scanf("%s", buf);
  int n = strlen(buf);

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < AC.tot; ++j) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < AC.tot; ++j) {
      if (AC.end[j] || dp[i - 1][j] == inf) continue;
      for (int k = 0; k < 4; ++k) {
        int t = AC.next[j][k];
        if (AC.end[t]) continue;
        dp[i][t] = min(dp[i][t], dp[i - 1][j] + !(AC.getid(buf[i - 1]) == k));
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < AC.tot; ++i) {
    ans = min(ans, dp[n][i]);
  }
  ans = (ans == inf ? -1 : ans);
  printf("Case %d: %d\n", kase, ans);
}
int main() {
  int kase = 0;
  while (scanf("%d", &N) != EOF && N) {
    work(++kase);
  }
  return 0;
}
