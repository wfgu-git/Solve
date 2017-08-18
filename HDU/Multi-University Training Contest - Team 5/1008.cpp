#include <bits/stdc++.h>
using namespace std;
const int maxm = 10000 + 20;
const int maxn = 50 + 20;
int cont[maxm], a[maxm], tmp[maxm];
int n, m;
int b[maxm];
long long C[maxn][maxn];
void get_C() {
  C[1][0] = C[1][1] = 1LL;
  for (int i = 2; i < maxn; ++i){
    C[i][0] = 1;
    for (int j = 1; j < maxn; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
}
void init() {
  memset(a, 0, sizeof(a));
  memset(cont, 0, sizeof(cont));
}
void update(int x) {
  memset(tmp, 0, sizeof(tmp));
  for (int i = 1; i <= a[x]; ++i) {
    for (int j = m; j >= 0; --j) {
      tmp[i * x + j] += C[a[x]][i] * cont[j];
    }
  }
  for (int i = 1; i <= a[x]; ++i) {
    tmp[i * x] += C[a[x]][i];
  }
  for (int i = 1; i <= m; ++i) {
    cont[i] += tmp[i];
  }
}
void print(vector<int> &ans) {
  for (int i = 1; i <= m; ++i) {
    while (a[i]--) {
      ans.push_back(i);
    }
  }
  int sz = ans.size();
  for (int i = 0; i < sz; ++i) {
    printf("%d%c", ans[i], (i == sz - 1 ? '\n' : ' '));
  }
}
int main() {
  get_C();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; ++i) {
      scanf("%d", b + i);
    }
    for (int i = 1; i <= m; ++i) {
      if (!b[i]) continue;
      a[i] = b[i] - cont[i];
      if (!a[i]) continue;
      update(i);
    }
    vector<int> ans;
    print(ans);
  }
  return 0;
}
/*
100
5 7
1 3 5 7 7 5 3 1
*/
