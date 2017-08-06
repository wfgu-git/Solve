#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
char grid[maxn][maxn];
bool check(int n, int m)
{
    if (n % 3 == 0) {
      for (int i = 0; i < n / 3; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (grid[i][j] != grid[0][0])
          {
            return false;
          }
        }
      }
      for (int i = n / 3; i < n / 3 * 2; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (grid[i][j] != grid[n/3][0])
          {
            return false;
          }
        }
      }
      for (int i = n / 3 * 2; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (grid[i][j] != grid[n/3 * 2] [0])
          {
            return false;
          }
        }
      }
      set<char> st({grid[0][0], grid[n/3][0], grid[n/3 * 2][0]});
      if (st.size() != 3)
      {
        return false;
      }
    }
    else
    return false;
    return true;
}

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    static char tmp[maxn][maxn];
    int ans = false;
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
      for (int j = 0; j < m; j++)
      {
        tmp[i][j] = grid[i][j];
      }
    }
    ans = check(n, m);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        grid[i][j] = tmp[j][i];
      }
    }
    ans = ans || check(m, n);
    if (ans)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }

  }
  return 0;
}
