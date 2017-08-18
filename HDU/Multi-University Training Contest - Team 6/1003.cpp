#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int n;
struct INFO {
  int val, tid;
  bool operator < (const INFO& rhs) const {
    return val < rhs.val;
  }
} ;
int ans[maxn];
void work() {
  scanf("%d", &n);
  vector<INFO> st;
  for (int i = 1; i <= n; ++i) {
    static int x;
    scanf("%d", &x);
    st.push_back({x, i});
  }
  sort(st.begin(), st.end());
  reverse(st.begin(), st.end());
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < (int)st.size(); ++j) {
      const INFO& x = st[j];
      if (x.tid % i != 0) {
        ans[i] = x.val;
        break;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    printf("%d%c", ans[i], (i == n ? '\n' : ' '));
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
