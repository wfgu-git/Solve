#include <cstring>
const int maxn = 50000;
int vis[maxn], mu[maxn], prime[maxn], tot;
void Mobius () {
  memset(vis, 0, sizeof(vis));
  mu[1] = 1;
  tot = 0;
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] < maxn; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}

// easy
void mobius(ll mn)
{
    mu[1]=1;
    for(ll i=1;i<=mn;i++){
        for(ll j=i+i;j<=mn;j+=i){
            mu[j]-=mu[i];
        }
    }
}
