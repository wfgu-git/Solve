/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct Deque {
  ll val;
  int idx;
} Q[maxn];
int head, tail, pos;
int a[maxn];
ll dp[maxn];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int n;
  ll m;
  while (~scanf("%d%lld", &n, &m)) {
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] > m) {
        flag = 0;
      }
    }
    if (!flag) {
      puts("-1");
      continue;
    }
    head = 1, tail = 0, pos = 1;
    ll sum = a[1];
    dp[1] = a[1];
    Q[++tail] = {a[1], 1};
    for (int i = 2; i <= n; ++i) {
      sum += a[i];
      while (sum > m && pos < i) {
        sum -= a[pos];
        pos++;
      }
      while (head <= tail && Q[tail].val <= a[i]) {
        --tail;
      }
      ++tail;
      Q[tail] = {a[i], i};
      while (head <= tail && Q[head].idx < pos) {
        ++head;
      }
      dp[i] = dp[pos - 1] + Q[head].val;
      for (int j = head; j <= tail - 1; ++j) {
        dp[i] = min(dp[i], dp[Q[j].idx] + Q[j + 1].val);
      }
    }
    printf("%lld\n", dp[n]);
  }
}
