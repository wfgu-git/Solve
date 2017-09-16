/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int p = 998244353;

ll n, m;
ll mod_pow(ll x, ll n) {
  ll ans = 1, base = x % p;
  while (n) {
    if (n & 1)
      ans = ans * base % p;
    base = base * base % p;
    n >>= 1;
  }
  return ans;
}
ll C(ll n, ll m) {
  if (m > n) return 0;
  ll ans = 1;
  for (int i = 1; i <= m; ++i) {
    ll a = (n + i - m) % p;
    ll b = i;
    ans = ans * (a * mod_pow(b, p - 2) % p) % p;
  }
  return ans;
}
ll lucas(ll n, ll m) {
  if (m == 0) return 1;
  return C(n % p, m %p) * lucas(n / p, m / p) % p;
}

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  int t;
  while (cin >> n >> m) {
    t = n - m;
    if (t & 1 || m > n) {
      cout << 0 << endl;
      continue;
    }
    ll ret = 0;
    int N, K;
    if (n & 1) {
      N = (n + 1) / 2;
      K = (m + 1) / 2;
      ret = (mod_pow(4, K - 1) * (2 * N - 1) % p)* lucas(N + K - 1, 2 * K - 1) % p;
      // ret /= (N + K - 1);
      ret *= mod_pow(N + K - 1, p - 2);
      ret %= p;
    } else {
      N = n / 2;
      K = m / 2;
      ret = (mod_pow(4, K) * N) % p * lucas(N + K, 2 * K) % p;
      ret *= mod_pow(N + K, p -2);
      ret %= p;
    }
    if ((N + K) % 2 == 0) {
      cout << (ret + p) % p << endl;
    } else {
      cout << (-ret + p) % p<< endl;
    }
  }
  return 0;
}
