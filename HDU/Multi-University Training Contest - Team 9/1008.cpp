#include <bits/stdc++.h>
using namespace std;
const int maxn = 125250 + 20;
int N, M;
int mix[maxn];
multiset<int> st;
vector<int> ans;
void debug() {for (const int&x : st) printf(" %d ", x);puts("");}
void work() {
  st.clear(); ans.clear();
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    st.insert(x);
  }
  if (M == 1) {
    printf("1\n%d\n", *st.begin());
    return;
  }
  auto it = st.begin();
  int x1 = *st.begin(); st.erase(it);
  it = st.begin();
  int x2 = *st.begin(); st.erase(it);
  ans.push_back(x1); ans.push_back(x2);
  st.erase(st.find(x1 + x2));
  // debug();
  while (st.size()) {
    int x = *st.begin();
    for (const int& y : ans) {
      st.erase(st.find(x + y));
      // debug();
    }
    st.erase(st.find(x));
      // debug();
    ans.push_back(x);
  }
  int sz = ans.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) {
    printf("%d%c", ans[i], (i == sz - 1 ? '\n' : ' '));
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d", &M) != EOF) {
    work();
  }
  return 0;
}
