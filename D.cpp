#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
typedef long long ll;
ll a[maxn];
int atwo[maxn], afive[maxn];
int ans;
int n, k;
bool cmp_by_two(int x, int y)
{
  return atwo[x] > atwo[y];
}
bool cmp_by_five(int x, int y)
{
  return afive[x] > afive[y];
}
void dfs(int two, int five, vector<int> & st, int d)
{
  if (k == d)
  {
    ans = max(ans, min(two, five));
    return;
  }
  if (st.size() + d < k)
  {
    return;
  }
  if (two < five)
  {
    sort(st.begin(), st.end(), cmp_by_two);
  }
  else sort(st.begin(), st.end(), cmp_by_five);
  int heaustic = min(two, five);
  for (int i = 0; i < k - d; i++)
  {
    heaustic += two<five?atwo[st[i]]: afive[st[i]];
  }
  if (heaustic <= ans)
  {
    return;
  }
  for (int i = 0; i < st.size(); i++)
  {
    vector<int> nex;
    for (int j = i + 1; j < st.size(); j++)
    {
      nex.push_back(st[j]);
    }
    dfs(two + atwo[st[i]], five + afive[st[i]], nex, d + 1);
  }
}
int main()
{
  while(scanf("%d%d", &n, &k) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%lld", a + i);
      afive[i] = 0;
      while(a[i] % 5 == 0)
      {
        afive[i]++;
        a[i] /= 5;
      }
      atwo[i] = 0;
      while(a[i] % 2 == 0)
      {
        atwo[i]++;
        a[i] /= 2;
      }
    }
    ans = 0;
    vector<int> raw;
    for (int i = 0; i < n; i++)
    {
      raw.push_back(i);
    }
    dfs(0, 0, raw, 0);
    printf("%d\n", ans);
  }
}
