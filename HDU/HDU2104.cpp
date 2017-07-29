#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == -1 && m == -1) break;
    if (__gcd(n, m) == 1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
