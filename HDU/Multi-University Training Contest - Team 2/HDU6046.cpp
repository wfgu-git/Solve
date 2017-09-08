/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;


inline unsigned sfr(unsigned h, unsigned x) {
  return h >> x;
}
int f(ll i, ll j) {
  ll w = i * 1000000ll + j;
  int h = 0;
  for(int k = 0; k < 5; ++k) {
    h += (int) ((w >> (8 * k)) & 255);
    h += (h << 10);
    h ^= sfr(h, 6);
  }
  h += h << 3;
  h ^= sfr(h, 11);
  h += h << 15;
  return sfr(h, 27) & 1;
}

char s[1002][1002];
unordered_map<ll, pair<int, int> > mep;
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {

    for (int i = 1; i <= 1000; ++i) {
      scanf("%s", s[i] + 1);
    }

    mep.clear();
    for (int i = 1; i <= 992; ++i) {
      for (int j = 1; j <= 992; ++j) {
        ll tmp = 0;
        for (int p = 0; p < 8; ++p) {
          for (int q = 0; q < 8; ++q) {
            tmp <<= 1;
            if (s[i + p][j + q] == '1') {
              tmp |= 1;
            }
          }
        }
        mep[tmp] = make_pair(i, j);
      }
    }

    bool flag = 1;
    for (int i = 1; i <= 1e6 && flag; i += 984) {
      for (int j = 1; j <= 1e6 && flag; j += 984) {
        ll tmp = 0;
        for (int p = 0; p < 8; ++p) {
          for (int q = 0; q < 8; ++q) {
            tmp <<= 1;
            if (f(i + p, j + q)) {
              tmp |= 1;
            }
          }
        }
        if (mep.find(tmp) != mep.end()) {
          pair<int, int> p = mep[tmp];
          flag = 0;
          printf("Case #%d :%d %d\n", cas, i - p.first + 1, j - p.second + 1);
        }
      }
    }

  }
}
