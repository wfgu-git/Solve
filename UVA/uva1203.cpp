/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 5000;

struct INFO {
  int tid, per, t;

  bool operator < (const INFO& rhs) const {
    return t > rhs.t || (t == rhs.t && tid > rhs.tid);
  }
} ;
void work() {
  char s[20];
  priority_queue<INFO> Q;
  while (scanf("%s", s) && s[0] != '#') {
    int tid, per;
    scanf("%d%d", &tid, &per);
    INFO  tmp = {tid, per, per};
    Q.push(tmp);
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    INFO now = Q.top(); Q.pop();
    printf("%d\n", now.tid);
    now.t += now.per;
    Q.push(now);
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  work();
  return 0;
}
