/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <random>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;


std::mt19937 rng_engine{(size_t)(new char)};
std::uniform_int_distribution<int> dist{1, 1000000000};//1-1000 inclusive
int random_int = dist(rng_engine);
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
    int maxx = 1e9;
    BL = (ll)maxx + dist(rng_engine) % maxx;
    BR = (ll)maxx + dist(rng_engine) % maxx;
    ML = (ll)maxx + dist(rng_engine) % maxx;
    MR = (ll)maxx + dist(rng_engine) % maxx;
  }
} Hash[2];


char s[maxn], t[maxn];
int k;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  while (scanf("%s%s%d", Hash[0].str, Hash[1].str, &k) == 3) {
    memcpy(s, Hash[0].str, sizeof(Hash[0].str));
    memcpy(t, Hash[1].str, sizeof(Hash[1].str));
    // puts(s); puts(t);
    int n = strlen(Hash[0].str);
    int m = strlen(Hash[1].str);
    Hash[0].init();
    Hash[0].hash2(n);
    Hash[0].build();
    Hash[1].init();
    Hash[1].hash2(m);
    Hash[1].build();
    
    int ans = 0;
    for (int i = 0; i <= n - m; ++i) {
      int j = 0;
      int x = 0;
      while (x <= k && j < m) {
        while (x <= k && j < m && s[i + j] != t[j]) {
          ++j; ++x;
        }
        if (j >= m || x > k) break;
        int l = j, r = m;
        while (l + 1 < r) {
          int mid = (l + r) / 2;
          long long h1 = Hash[0].get(i + l, i + mid);
          long long h2 = Hash[1].get(l, mid);
          if (h1 == h2) {
            l = mid;
          } else {
            r = mid;
          }
        }
        if (l != m - 1) {
          ++x;
        }
        j = l + 2;
      }
      ans += x <= k;
    }
    printf("%d\n", ans);
  }
}
