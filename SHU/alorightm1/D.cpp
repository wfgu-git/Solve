/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 50 + 20;

int a[maxn];
int vis[maxn];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    memset(vis, 0, sizeof(vis));
    int n;
    scanf("%d", &n);
    for (int x, i = 0; i < n; ++i) {
      scanf("%d", &x);
      Q.push(x);
      a[i] = x;
    }
    priority_queue<int, vector<int>, greater<int> > Q;

  }
}
