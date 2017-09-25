/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;

priority_queue<int> Q;
pii stops[maxn];
bool comp(const pii& x, const pii& y) {
  return x.first > y.first;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      stops[i] = {x, y};
    }
    sort(stops, stops + n, comp);
    int L, P;
    scanf("%d%d", &L, &P);
    Q.push(P);
    int ans = 0;
    int idx = 0;
    while (L > 0 && !Q.empty()) {
      ans++;
      int t = Q.top(); Q.pop();
      L -= t;
      while (idx < n && L <= stops[idx].first) {
        Q.push(stops[idx++].second);
      }
    }
    printf("%d\n", L <= 0 ? ans - 1 : -1);
  }
}
