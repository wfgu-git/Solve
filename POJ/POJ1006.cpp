#include <cstdio>
#include <cstring>
using namespace std;
static int moder[3] = {23, 28, 33};
int a[3], d;
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
    ans = (ans + Mi * x * a[i]) % M;
  }
  if (ans < d) ans += M;
  return ans;
}
void solve(int kase) {
  int ans = crt(a, moder, 3);
  if (ans <= d) ans += 21252;
  printf("Case %d: the next triple peak occurs in %d days.\n", kase, ans - d);
}
int main() {
  int kase = 0;
  while (~scanf("%d%d%d%d", a + 0, a + 1, a + 2, &d)) {
    if (a[0] == -1 && a[1] == -1 && a[2] == -1) break;
    solve(++kase);
  }
  return 0;
}
