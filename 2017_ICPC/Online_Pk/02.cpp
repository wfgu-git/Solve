/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

const int oo = 1073741819;
int n, i, a[500005], rk[500006], sa[500006], Min, s;
char ch[500005];
void init() {
  int i, k;
  scanf("%d\n", &n);
  for (i = 1; i <= n; i++) scanf("%d", &sa[i]), rk[sa[i]] = i;
  k = rk[n], a[n] = 0;
  for (i = k; i >= 2; i--)
    if (rk[sa[i - 1] + 1] < rk[sa[i] + 1])
      a[sa[i - 1]] = a[sa[i]];
    else
      a[sa[i - 1]] = a[sa[i]] - 1;
  for (i = k; i <= n - 1; i++)
    if (rk[sa[i + 1] + 1] > rk[sa[i] + 1])
      a[sa[i + 1]] = a[sa[i]];
    else
      a[sa[i + 1]] = a[sa[i]] + 1;
  Min = oo;
  for (i = 1; i <= n; i++)
    if (a[i] < Min) Min = a[i];
  for (i = 1; i <= n; i++) printf("%c", a[i] - Min + 97);
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--)  init();
  return 0;
}
