/*
教练我要打ACM!
*/
/*
教练我要打ACM!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 20;

// mt19937 rng_engine{(size_t)(new char)};
// uniform_int_distribution<unsigned> dist{1, 1000000000};//1-1000 inclusive
// int random_int = dist(rng_engine);
struct Hash {
  ll BL, BR, ML, MR;
  unsigned long long psl[maxn], psr[maxn];
  char str[maxn];
  unsigned long long hs[maxn];
  void hash2(int n) {
    for (int i = 0; i <= n; ++i) {
      psl[i] = (i == 0 ? 1 : psl[i - 1] * BL) % ML;
    }
    for (int i = 0; i <= n; ++i) {
      psr[i] = (i == 0 ? 1 : psr[i - 1] * BR) % MR;
    }
  }
  void build() {
    int n = strlen(str);
    long long l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      l = (l * BL + str[i]) % ML;
      r = (r * BR + str[i]) % MR;
      if (l < 0) l += ML;
      if (r < 0) r += MR;
      hs[i + 1] = (l << 32) | r ;
    }
  }
  long long get(int b, int e) {
    unsigned long long el = (hs[e] >> 32);
    unsigned long long er = (hs[e] & 0xffffffffULL);
    unsigned long long bl = (hs[b] >> 32);
    unsigned long long br = (hs[b] & 0xffffffffULL);
    long long l = el - bl * psl[e - b] % ML;
    long long r = er - br * psr[e - b] % MR;
    if (l < 0) l += ML;
    if (r < 0) r += MR;
    return (l << 32) | r;
  }
  void init() {
    srand(123321);
    int maxx = 1e9;
    BL = (ll)maxx + rand() % maxx;
    BR = (ll)maxx + rand() % maxx;
    ML = (ll)maxx + rand() % maxx;
    MR = (ll)maxx + rand() % maxx;
  }
} Hash[2];

char s[maxn], t[maxn];
int n, m;
ll a[maxn];
bool check1(int mid) {
  int cont = 0;
  for (int i = 0; i + mid - 1 < n; ++i) {
    // tmp.insert(Hash[0].get(i, i + mid));
    a[cont++] = Hash[0].get(i, i + mid);
  }
  sort(a, a + cont);
  for (int i = 0; i + mid - 1 < m; ++i) {
    long long t = Hash[1].get(i, i + mid);
    if (binary_search(a, a + cont, t)) {
      return true;
    }
  }
  return false;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%s%s", Hash[0].str, Hash[1].str) != EOF) {
    n = strlen(Hash[0].str);
    m = strlen(Hash[1].str);
    Hash[0].init();
    Hash[0].hash2(n);
    Hash[0].build();
    Hash[1].init();
    Hash[1].hash2(m);
    Hash[1].build();

    int lb = 0, ub = min(n,  m);
    int ans = 0;
    while (lb <= ub) {
     int mid = (lb + ub) / 2;
     if (check1(mid)) {
       lb = mid + 1;
       ans = mid;
     } else {
       ub = mid - 1;
     }
    }
    printf("%d\n", ans);
  }
}
