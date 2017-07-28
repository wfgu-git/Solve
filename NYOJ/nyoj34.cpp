#include <bits/stdc++.h>
using namespace std;
static int moder[3] = {3, 5, 7};
int a[3];
void extend_gcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int crt(int *a, int *m, int n) {
  int M = 1;
  for (int i = 0; i < n; i++) M *= m[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    int Mi = M / m[i];
    extend_gcd(Mi, m[i], x, y);
    ans = (ans + Mi * x * a[i]);
  }
  if (ans < 0) ans += M;
  return ans;
}
void solve() {
  printf("%d\n", crt(a, moder, 3));
}
int main() {
  while (scanf("%d%d%d", a + 0, a + 1, a + 2) != EOF) {
    solve();
  }
  return 0;
}
