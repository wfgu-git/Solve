#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int st, tar;
int step[maxn * 6];
int bfs() {
  memset(step, -1, sizeof(step));
  queue<int> q;
  q.push(st);
  step[st] = 0;

  while (!q.empty()) {
    int now = q.front(); q.pop();
    if (now == tar) return step[now];
    if (now - 1 >= 0 && step[now - 1] == -1) {
      step[now - 1] = step[now] + 1;
      q.push(now - 1);
    }
    if (now + 1 <= tar && step[now + 1] == -1) {
      step[now + 1] = step[now] + 1;
      q.push(now + 1);
    }
    if (now * 2 <= tar * 2 + 20 && step[now * 2] == -1) {
      step[now * 2] = step[now] + 1;
      q.push(now * 2);
    }
  }
}
void solve() {
  int ans = bfs();
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d%d", &st, &tar) != EOF) {
    solve();
  }
  return 0;
}
