#include <random>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6;

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

//easy

const int base = 1000009;
unsigned long long hss[maxn];
unsigned long long hst[maxn];
unsigned long long p[maxn];
void init(char s[], int n, unsigned long long hs[]) {
  hs[0] = 0;
  for (int i = 0; i < n; ++i) {
    hs[i + 1] = hs[i] * base + (s[i] - 'a' + 1);
  }
}
// get [l, r] ==> get(l + 1, r + 1);
unsigned long long get(unsigned long long hs[], int l, int r) {
  return hs[r] - hs[l - 1] * p[r - l + 1];
}
