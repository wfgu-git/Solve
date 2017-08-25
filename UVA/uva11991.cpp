/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

int n, m, x, y;
void work() {
  map<int, vector<int> > mp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (!mp.count(x)) mp[x] = vector<int>();
    mp[x].push_back(i + 1);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    if (!mp.count(y) || mp[y].size() < x)  puts("0");
    else printf("%d\n", mp[y][x - 1]);
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &n, &m) != EOF) {
    work();
  }
  return 0;
}
