/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 20;

int N, M;
int sumr[maxn], sumc[maxn];
void add_limit(int u, int v, char c, int d) {
  
}
void work() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &sumr[i]);
  }
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &sumc[i]);
  }
  int K;
  scanf("%d", &K);
  int u, v, d;
  char op[2];
  for (int i = 0; i < K; ++i) {
    scanf("%d%d", &u, &v);
    scanf("%s", op);
    scanf("%d", &d);
    add_limit(u, v, op[0], d);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
