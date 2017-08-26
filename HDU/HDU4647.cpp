/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N, M;
double Wv[maxn];
void work() {
  for (int i = 0; i < N; ++i) {
    scanf("%lf", Wv + i);
  }
  for (int i = 0; i < M; ++i) {
    int from, to;
    double cost;
    scanf("%d%d%lf", &from, &to, &cost);
    Wv[from - 1] += cost / 2;
    Wv[to - 1] += cost / 2;
  }
  sort(Wv, Wv + N);
  reverse(Wv, Wv + N);
  double sum = 0;
  for (int i = 0; i < N; ++i) {
    if (!(i & 1)) {
      sum += Wv[i];
    } else {
      sum -= Wv[i];
    }
  }
  printf("%.0f\n", sum);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
