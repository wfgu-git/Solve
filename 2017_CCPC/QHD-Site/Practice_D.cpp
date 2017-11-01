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

int fi, se, L;
void dfs(string str, int depth) {
  if (depth == L / 2) {
    for (char & ch : str) {
      if (ch == '#') ch = '0' + se;
    }
    ll x = 0LL;
    for (char & ch : str) {
      x = x * 10LL + (ch - '0');
    }
    if (miller_rabin(x)) cout << x << '\n';
    return;
  }

  for (int i = 0; i < L; ++i) {
    if (str[i] != '#') continue;
    str[i] = '0' + fi;
    dfs(str, depth + 1);
    str[i] = '#';
  }
}
void work() {
  // get list
  for (int a = 1; a <= 9; ++a) {
    fi = a;
    for (int b = 1; b <= 9; ++b) if (a != b && b & 1) {
      se = b;
      for (int i = 2; i <= 18; i += 2) {
        if ((a * i / 2 + b * i / 2) % 3 == 0) continue;
        if (i % 3 == 0) continue;
        L = i;
        dfs(string(L, '#'), 0);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("data.out", "w", stdout);
  work();
}
