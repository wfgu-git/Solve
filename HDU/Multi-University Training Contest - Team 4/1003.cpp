#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000010;
const int moder = 998244353;
ll l, r, k, d;
ll PrimeList[maxn];
ll ans[maxn];
ll temp[maxn];
int PrimeNum;
bool IsNotPrime[maxn]; // IsNotPrime[i] = 1表示i + L这个数是素数.
int notprime[maxn];
void getPrime() {
  notprime[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    if (!notprime[i]) PrimeList[PrimeNum++] = i;
    for (int j = 0; j < PrimeNum && i * PrimeList[j] < maxn; ++j) {
      notprime[i * PrimeList[j]] = 1;
      if (i % PrimeList[j] == 0) break;
    }
  }
}
void SegmentPrime(ll L, ll R)
{ // 求区间[L, R]中的素数.
     ll i, j;
     ll SU = sqrt(1.0 * R);
     d = R - L + 1;
     for (i = 0; i < d; i++) {
       IsNotPrime[i] = 0; // 一开始全是素数.
       temp[i] = i + L;
       ans[i] = 1LL;
     }
     for (i = (L % 2 != 0); i < d; i += 2) {
       IsNotPrime[i] = 1; // 把偶数的直接去掉.
       ll cnt = 0;
       while (temp[i] % 2LL == 0LL) {
         temp[i] /= 2;
         cnt++;
       }
       ans[i] = (ans[i] * (k * cnt % moder + 1LL)) % moder;
     }
     for (int su = 1; PrimeList[su] <= SU; ++su)
    //  for (i = 3; i <= SU; i += 2)
     {
       i = PrimeList[su];
           if (i > L && IsNotPrime[i - L]) continue; // IsNotPrime[i - L] == 1说明i不是素数.
           j = (L / i) * i; // j为i的倍数，且最接近L的数.
           if (j < L) j += i;
           if (j == i) j += i; // i为素数，j = i说明j也是素数，所以直接 + i.
          j = j - L;
          for (; j < d; j += i) {
            IsNotPrime[j] = 1; // 说明j不是素数(IsNotPrime[j - L] = 1).
            ll cnt = 0;
            while(temp[j] % i == 0) {
              temp[j] /= i;
              ++cnt;
            }
            ans[j] = (ans[j] * (k * cnt % moder + 1LL)) % moder;
          }
     }
     if (L <= 1) IsNotPrime[1 - L] = 1;
     if (L <= 2) IsNotPrime[2 - L] = 0;
    //  PrimeNum = 0;
    //  for (i = 0; i < d; i++) if (!IsNotPrime[i]) PrimeList[PrimeNum++] = i + L;
    for (int i = 0; i < d; ++i) {
      if (temp[i] != 1) {
        ans[i] = (ans[i] * (k * 1LL % moder + 1LL)) % moder;
      }
    }
}
int main() {
  getPrime();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%lld%lld%lld", &l, &r, &k);
    SegmentPrime(l, r);
    ll ac = 0;
    for (int i = 0; i < d; ++i) {
      ac += ans[i];
      ac %= moder;
    }
    printf("%lld\n", ac);
  }
}
