/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

long long power(long long v, long long p, long long m) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * v % m;
    v = v * v % m;
    p >>= 1;
  }

  return r;
}

bool witness(long long a, long long p) {
  int k = 0;
  long long q = p - 1;
  while ((q & 1) == 0) ++k, q >>= 1;
  long long v = power(a, q, p);
  if (v == 1 || v == p - 1) return false;  // probably prime number
  while (k-- != 0) {
    v = v * v % p;
    if (v == p - 1) return false;
  }

  return true;  // composite number
}

bool miller_rabin(long long p) {
  if (p == 2) return true;
  if (p % 2 == 0) return false;

  for (int i = 0; i != 50; ++i) {
    long long a = std::rand() % (p - 1) + 1;
    if (witness(a, p)) return false;
  }

  return true;
}
bool vis[10] = {0};
void dfs(ll x, int depth, int limit) {
  if (depth == limit) {
    if (miller_rabin(x)) {
      printf("%lld\n", x);
    }
  }
  for (int i = 1; i <= 9; ++i) {
    if (vis[i]) continue;
    vis[i] = 1;
    dfs(x * 10 + i, depth + 1, limit);
    vis[i] = 0;
  }
}
void work() {
  for (int i = 2; i <= 18; i += 2) {
    if (i % 3 == 0) continue;
    dfs(0, 0, i);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
