#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int x[maxn], y[maxn];
bool check(int length, int width, int x1, int y1, int x2, int y2)
{
  if (length >= x1 + x2 && width >= max(y1,y2))
  {
     return true;
  }
  else if (width >= y1 + y2 && length >= max(x1, x2))
  {
    return true;
  }
  return false;
}
int main()
{
  int n, a, b;
  while(scanf("%d%d%d", &n, &a, &b) != EOF)
  {
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", x + i, y + i);
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (check(a, b, x[i], y[i], x[j], y[j]) || check(a, b, y[i], x[i], x[j], y[j]) || check(a, b, x[i], y[i], y[j], x[j]) || check(a, b, y[i], x[i], y[j], x[j]))
        {
          ans = max(ans, x[i] * y[i] + x[j] * y[j]);
        }
      }
    }
    printf("%d\n", ans);
  }
}
