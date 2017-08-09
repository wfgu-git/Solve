#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
struct Pia {
  long long a, b, c;
  int tag, input_time;
  Pia() {}
  Pia(long long _a, long long _b, int tid) : a(_a), b(_b) {
    this->c = _a + _b;
    this->input_time = tid;
    if (a < b) tag = -1;
    else if (a == b) tag = 0;
    else tag = 1;
  }
  bool operator < (const Pia& rhs) {
    if (c == rhs.c) {
      if (tag == rhs.tag) {
        return input_time > rhs.input_time;
      }
      return tag < rhs.tag;
    } else {
      return c < rhs.c;
    }
  }
} ;
int n;
void work() {
  scanf("%d", &n);
  vector<Pia> info;
  for (int i = 0; i < n; ++i) {
    static int a, b;
    scanf("%d%d", &a, &b);
    info.push_back(Pia(a, b, i));
  }
  sort(info.rbegin(), info.rend());
  for (Pia& x : info) {
    char t;
    if (x.tag < 0) t = '<';
    else if (x.tag == 0) t = '=';
    else t = '>';
    printf("%lld+%lld=[%c%lld]\n", x.a, x.b, t, x.c);
  }
  printf("\n");
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
