#include <bits/stdc++.h>
using namespace std;
const int maxm = 10000 + 10;
struct INFO {
  double mark;
  int tid;
  bool operator <(const INFO& rhs) const {
    if (mark == rhs.mark) return tid > rhs.tid;
    return mark < rhs.mark;
  }
} a[maxm];
int N, M, K;
inline void work() {
  for (int i = 0; i < M; ++i) {
    a[i].tid = i;
    a[i].mark = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      double tmp = 0L;
      scanf("%lf", &tmp);
      a[j].mark += tmp;
    }
  }
  sort(a, a + M);
  reverse(a, a + M);
  set<int, greater<int> > ans;
  for (int i = 0; i < K; ++i) {
    ans.insert(a[i].tid + 1);
  }
  bool fi = true;
  for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
    if (fi) {fi = false; printf("%d", *it);}
    else printf(" %d", *it);
  }
  printf("\n");
}
int main() {
  while (scanf("%d%d%d", &N, &M, &K) != EOF) {
    work();
  }
}
