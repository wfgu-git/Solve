#include <bits/stdc++.h>
using namespace std;
const long maxn = 200000;
long prime[maxn] = {0},num_prime = 0;
int isNotPrime[maxn] = {1, 1};
void get_prime() {
  for (int i = 2; i < maxn; ++i) {
    if (!isNotPrime[i]) prime[++num_prime] = i;
    for (int j = 1; j <= num_prime && i * prime[j] < maxn; ++j) {
      isNotPrime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
