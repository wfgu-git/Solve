/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
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
} hs;

int main() {
  int M, L;
  map<unsigned long long, int> mep;
  while (scanf("%d%d", &M, &L) != EOF) {
    scanf("%s", hs.str);
    int n = strlen(hs.str);
    hs.init();
    hs.hash2(n);
    hs.build();
    int ans = 0;
    for (int i = 0; i < L && i + M * L < n; ++i) {
      mep.clear();
      for (int j = i; j < i + M * L; j += L) {
        ++mep[hs.get(j, j + L)];
      }

      if (mep.size() == M) ++ans;

      unsigned long long tmp;
      for (int j = i + M * L; j + L - 1 < n; j += L) {
        tmp = hs.get(j - M *L, j - (M - 1) * L);
        if (!--mep[tmp]) mep.erase(tmp);
        ++mep[hs.get(j, j + L)];
        if (mep.size() == M) ++ans;
      }
    }
    printf("%d\n", ans);
  }
}
