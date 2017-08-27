/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N;
struct Cow {
  int s, e;
  int tid;
  bool operator < (const Cow& rhs) const {
    if (s == rhs.s) return e > rhs.e;
    return s < rhs.s;
  }
} ;
int ans[maxn];
void work() {
  memset(ans, 0, sizeof(ans));
  multiset<Cow> st;
  for (int i = 0; i < N; ++i) {
    static int l, r;
    cin >> l >> r;
    st.insert({l, r, i});
  }

  multiset<Cow>::iterator it;
  int s, e;
  int tot = 0;
  while (st.size()) {
    Cow now = *st.begin(); st.erase(st.begin());
    s = now.s;
    e = now.e;
    ans[now.tid] = ++tot;
    while (st.size() && (it = st.lower_bound({e + 1, inf})) != st.end()) {
      e = it->e;
      ans[it->tid] = tot;
      st.erase(it);
    }
  }
  cout << tot << endl;
  for (int i = 0; i < N; ++i) {
    cout << ans[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N) {
    work();
  }
  return 0;
}
