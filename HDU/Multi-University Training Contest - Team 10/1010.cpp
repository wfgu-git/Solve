/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

struct comp {
  bool operator () (const pii& x, const pii& y) const {
    return x.first < y.first;
  }
} ;
struct dist {
  bool operator () (const pii& x, const pii& y) const {
    return x.second > y.second;
  }
} ;
int n;
multiset<pii, comp> task;
multiset<pii, dist> ma;
void work() {
  task.clear(); ma.clear();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    task.insert({l, r});
  }
  multiset<pii, comp>::iterator it;
  multiset<pii, dist>::iterator p;
  int s, e;
  while (task.size()) {
    it = task.begin();
    pii now = *it;
    task.erase(it);
    s = now.first;
    e = now.second;
    if ((p = ma.lower_bound({0, s})) != ma.end()) {
      ma.insert({p->first, e});
      ma.erase(p);
    } else {
      ma.insert(now);
    }
  }
  ll sum = 0;
  for (const pii& x : ma) {
    sum += 1LL * (x.second - x.first);
  }
  printf("%d %lld\n", (int)ma.size(), sum);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
