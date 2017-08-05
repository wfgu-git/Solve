#include <bits/stdc++.h>
using namespace std;
const long maxn = 200000;
long prime[maxn] = {0}, num_prime = 0;
int not_prime[maxn] = {1, 1};
void get_prime() {
  for (int i = 2; i < maxn; ++i) {
    if (!not_prime[i]) prime[++num_prime] = i;
    for (int j = 1; j <= num_prime && i * prime[j] < maxn; ++j) {
      not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

int phi[maxn];
void get_phi() {
  int i, j, k;
  k = 0;
  for (i = 2; i < maxn; i++) {
    if (not_prime[i] == false) {
      prime[k++] = i;
      phi[i] = i - 1;
    }
    for (j = 0; j < k && i * prime[j] < maxn; j++) {
      not_prime[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      }
    }
  }
}
