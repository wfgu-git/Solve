#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
set<pii> pos;
int N;
void work() {
  bool flag = false;
  pos.clear();
  scanf("%d", &N);
  pii now = {0, 0};
  pos.insert(now);
  int dir = 0, ans = -1;
  for (int i = 1; i <= N; ++i) {
    int x;
    long long d;
    scanf("%d", &x);
    if (flag) continue;
    d = 1LL * x;
    if (dir == 0) {
      now.second += d;
    } else if (dir == 1) {
      now.first += d;
    } else if (dir == 2) {
      now.second -= d;
    } else if (dir == 3) {
      now.first -= d;
    }
    if (pos.count(now)) {
      ans = i;
      flag = true;
    }
     pos.insert(now);
    dir++;
    dir %= 4;
  }
  if (flag) printf("%d\n", ans);
  else printf("Catch you\n");
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
