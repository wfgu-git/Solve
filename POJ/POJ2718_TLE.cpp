/*
教练我要打ACM!
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

int T;
vector<int> st;
bool vis[11];
int ans;
void work() {
  st.clear();
  int tmp;
  char ch;
  do {
    scanf("%d%c", &tmp, &ch);
    st.push_back(tmp);
  } while(ch != '\n');
  if (st.size() == 10) {
    puts("247");
    return;
  }
  sort(st.begin(), st.end());
  ans = inf;
  vector<int> x, y;
  for (int i = 0; i < 20; ++i) {
    random_shuffle(st.begin(), st.end());
    for (int i = 1; i < st.size(); ++i) {
      for (int l = 0; l + i < (int)st.size(); ++l) {
        x.clear(); y.clear();
        memset(vis, 0, sizeof(vis));
        int r = l + i - 1;
        for (int j = l; j <= r; ++j) {
          vis[st[j]] = true;
          x.push_back(st[j]);
        }
        for (int j = 0; j < st.size(); ++j) {
          if (!vis[st[j]]) y.push_back(st[j]);
        }

        do {
          if (x[0] == 0 && x.size() > 1) continue;
          int tmpx = 0;
          for (int j = 0; j < x.size(); ++j) tmpx = tmpx * 10 + x[j];
          sort(y.begin(), y.end());
          do {
            if (y[0] == 0 && y.size() > 1) continue;
            int tmpy = 0;
            for (int j = 0; j < y.size(); ++j) tmpy = tmpy * 10 + y[j];
            ans = min(ans, abs(tmpx - tmpy));
          } while(next_permutation(y.begin(), y.end()));
        } while(next_permutation(x.begin(), x.end()));
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/solve/data.out", "w", stdout);
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
}
