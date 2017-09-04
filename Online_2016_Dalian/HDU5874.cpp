#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    long long k = (n - (n / 2)) * 1LL * (n / 2);
    printf("%s\n", k <= m ?"T" : "F");
  }
  return 0;
}
