#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
int N, M;
int a[maxn];
inline int lowbit(int x) {return x & (-x);}
inline void work() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", a + i);
  }
  vector<int> st;
  while (M) {
    st.push_back(lowbit(M));
    M -= lowbit(M);
  }
  for (int& x : st) {
    for (int i = x + 1; i <= N; ++i) {
      a[i] ^= a[i - x];
    }
  }
  for (int i = 1; i <= N; ++i) {
    printf("%d%c", a[i], (i == N ? '\n' : ' '));
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
