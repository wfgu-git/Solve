/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 750 + 2;

int n;
struct INFO {
  int s, b;
  INFO(int s, int b) : s(s), b(b) {}
  bool operator < (const INFO& rhs) const {
    return s > rhs.s;
  }
} ;
void merge(int *A, int *B, int *C, int n) {
  priority_queue<INFO> Q;
  for (int i = 0; i < n; ++i) {
    Q.push(INFO(A[i] + B[0], 0));
  }
  for (int i = 0; i < n; ++i) {
    INFO now = Q.top(); Q.pop();
    C[i] = now.s;
    int b = now.b;
    if (b + 1 < n) Q.push(INFO(now.s - B[b] + B[b + 1], b + 1));
  }
}
int a[maxn][maxn];
void work() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
    sort(a[i], a[i] + n);
  }
  for (int i = 1; i < n; ++i) {
    merge(a[0], a[i], a[0], n);
  }

  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[0][i], (i == n - 1 ? '\n' : ' '));
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d", &n) != EOF) {
    work();
  }
  return 0;
}
