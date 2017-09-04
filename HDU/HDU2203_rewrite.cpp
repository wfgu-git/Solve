/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int moder = 998244353;
const int maxn = 100000 + 20;
const int base = 163;

unsigned long long hstable[maxn];
unsigned long long p[maxn];
unsigned long long hskey;
string s, t;
void init() {
  p[0] = 1;
  hstable[0] = 0;
  for (int i = 1; i < maxn; ++i) {
    p[i] = p[i - 1] * base;
  }
  int sn = s.size();
  for (int i = 0; i < sn; ++i) {
    hstable[i + 1] = hstable[i] * base + (s[i] - 'A');
  }
  int tn = t.size();
  hskey = 0;
  for (int i = 0; i < tn; ++i) {
    hskey = hskey * base + (t[i] - 'A');
  }
}
unsigned long long get(int l, int r) {
  return hstable[r] - hstable[l - 1] * p[r - l + 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> s >> t) {
    int sn = s.size();
    int tn = t.size();

    s = s + s;
    init();
    bool flag = false;
    for (int i = 0; i < sn; ++i) {
      if (get(i + 1, i + tn) == hskey) {
        cout << "yes" << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << "no" << endl;
  }
  return 0;
}
