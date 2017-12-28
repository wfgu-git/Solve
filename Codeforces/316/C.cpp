/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 300000 + 20;

char s[maxn];
int L[maxn];
void work() {
  int n, m;
  scanf("%d%d%s", &n, &m, s + 1);
  s[0] = 'a';
  s[n + 1] = 'a';

  L[0] = 0;
  int len = 0, tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '.') {
      if (s[i - 1] != '.') {
        ++tot;
      }
      ++len;
    }
  }


  int ans = len - tot;
  int last = ans;
  for (int i = 0; i < m; ++i) {
    int pos;
    char ch[2];
    scanf("%d%s", &pos, ch);
    if (s[pos] == '.' && ch[0] == '.') {
      printf("%d\n", last);
      continue;
    }
    if (s[pos] != '.' && ch[0] != '.') {
      printf("%d\n", last);
      continue;
    }

    if (s[pos] == '.' && ch[0] != '.') {
      if (s[pos - 1] == '.' && s[pos + 1] == '.') {
        --len;
        ++tot;
      } else if (s[pos - 1] != '.' && s[pos + 1] != '.') {
        --len;
        --tot;
      } else {
        --len;
      }
    } else if (s[pos] != '.' && ch[0] == '.') {
      if (s[pos - 1] == '.' && s[pos + 1] == '.') {
        ++len;
        --tot;
      } else if (s[pos - 1] != '.' && s[pos + 1] != '.'){
        ++len;
        ++tot;
      } else {
        ++len;
      }
    }
    s[pos] = ch[0];
    ans = len - tot;
    printf("%d\n", ans);
    last = ans;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);

  work();
}
