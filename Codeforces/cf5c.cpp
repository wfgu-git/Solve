#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 20;
int ans[maxn] = {1};
stack<char> st;
int main() {
  static char s[maxn];
  scanf("%s", s);
  int n = strlen(s);
  int p, mxlen, cnt;
  p = cnt = mxlen = 0;
  while (p < n) {
    if (st.empty()) cnt = 0;
    if (s[p] == '(') {
      st.push('(');
    } else {
      if (st.empty()) {
        cnt = 0;
      } else {
        st.pop();
        cnt++;
        ans[cnt * 2]++;
        mxlen = max(mxlen, cnt * 2);
      }
    }
    ++p;
  }
  printf("%d %d\n", mxlen, ans[mxlen]);
  return 0;
}
